#pragma once
#include <map>
#include <unordered_map>
#include <string>
#include <Profiling/ScopedTimer.h>

namespace Algorithms::Backtracking{

    void dfs(int i, std::string& cur,
             std::map<char,int>& count,
             std::unordered_set<std::string>& seen,
             int& ans,
             std::string_view tiles){
        MEASURE_FUNCTION();
        if(i > tiles.length()){
            return;
        }

        for(int j = 0; j < tiles.length(); ++j){

            if(count[tiles[j]] > 0){

                cur += tiles[j];

                if(seen.find(cur) == seen.end()){
                    seen.insert(cur);
                    count[tiles[j]]--;
                    ans++;
                    dfs(i + 1, cur, count, seen, ans, tiles);
                    count[tiles[j]]++;
                }
                cur = cur.substr(0, cur.length() - 1);
            }

        }
    }

    int numTilePossibilities(std::string_view tiles) {
        MEASURE_FUNCTION();
        if(tiles.length() <= 1){
            return tiles.length();
        }

        std::map<char,int> count;

        for(const auto& c : tiles){
            count[c]++;
        }

        std::unordered_set<std::string> seen;
        int ans = 0;
        std::string cur = "";

        dfs(0, cur, count, seen, ans, tiles);
        return ans;
    }

    //========================================================================================
    //Optimized

    void dfsOptimized(int i, std::string& cur,
             int* count,
             std::unordered_set<std::string>& seen,
             int& ans,
             std::string_view tiles){
        MEASURE_FUNCTION();
        if(i > tiles.length()){
            return;
        }

        for(int i = 0; i < 26; ++i){
            const auto c = static_cast<char>(i) + 'A';

            if(count[i] > 0){
                count[i]--;
                cur += c;
            }
        }

        for(int j = 0; j < tiles.length(); ++j){
            const auto charValue = tiles[j] - 'A';

            if(count[charValue] > 0){

                cur += tiles[j];

                if(seen.find(cur) == seen.end()){
                    seen.insert(cur);
                    count[charValue]--;
                    ans++;
                    dfsOptimized(i + 1, cur, count, seen, ans, tiles);
                    count[charValue]++;
                }
                cur = cur.substr(0, cur.length() - 1);
            }
        }
    }

    int numTilePossibilitiesOptimized(std::string_view tiles) {

        MEASURE_FUNCTION();
        if(tiles.length() <= 1){
            return static_cast<int>(tiles.length());
        }

        int count[26];
        std::fill(std::begin(count), std::end(count), 0);

        for(const auto& c : tiles){
            count[c - 'A']++;
        }

        std::unordered_set<std::string> seen;
        int ans = 0;
        std::string cur;

        dfsOptimized(0, cur, count, seen, ans, tiles);
        return ans;
    }
}