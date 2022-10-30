#pragma once
#include <vector>

namespace Algorithms::Backtracking
{
    bool isRowSafe(int c, const std::string& row){
        for(int i = 0; i < row.length(); ++i){
            if(i != c){
                if(row[i] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }

    bool isColumnSafe(int r, std::vector<std::string>& cur){
        for(int i = 0; i < cur.size(); ++i){
            if(i != r){
                if(cur[i][0] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }

    std::tuple<int,int> findStartDiagonal(bool left, int r, int c, int n){
        if(left){
            while(r > 0 && c > 0){
                r--;
                c--;
            }
        } else {
            while(r > 0 && c < n - 1){
                r--;
                c++;
            }
        }
        return std::make_tuple(r, c);
    }

    bool isDiagonalSafe(int r, int c, std::vector<std::string>& cur){

        auto [leftRow, leftCol] = findStartDiagonal(true, r, c, cur.size());
        std::cout << "Size: " << cur.size() << std::endl;

        for(auto i = leftRow, j = leftCol; i < cur.size(), j < cur.size(); ++i, ++j){

            std::cout << "Left: " << i << " " << j << ", ";
            if(i != r && j != c){
                if(cur[i][j] == 'Q'){
                    return false;
                }
            }
        }

        std::cout << std::endl;

        auto [rightRow, rightCol] = findStartDiagonal(false, r, c, cur.size());

        for(auto i = rightRow, j = rightCol; i < cur.size(), j > 0; ++i, --j){

            std::cout << "Right: " << i << " " << j << ", ";
            if(i != r && j != c){
                if(cur[i][j] == 'Q'){
                    return false;
                }
            }
        }

        std::cout << std::endl;

        return true;
    }

    bool isSafe(int r, int c, std::vector<std::string>& cur){
        return isRowSafe(c, cur[r]) && isColumnSafe(r, cur) && isDiagonalSafe(r, c, cur);
    }

    void setQueens(int r, std::vector<std::string>& cur, std::vector<std::vector<std::string>>& ans){

        if(r == cur.size()){
            ans.push_back(cur);
            return;
        }

        for(int c = 0; c < cur.size(); ++c){
            if(isSafe(r, c, cur)){
                cur[r][c] = 'Q';
                setQueens(r + 1, cur, ans);
                cur[r][c] = '.';
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {

        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> cur (n, std::string(n,'.'));
        setQueens(0, cur, ans);
        return ans;
    }
}

