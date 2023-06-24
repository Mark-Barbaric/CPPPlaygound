#pragma once
#include <Profiling/ScopedTimer.h>

namespace Profiling{

    // uses a Leetcode question
    void dfs(int i, std::string& cur,
             std::map<char,int>& count,
             std::unordered_set<std::string>& seen,
             int& ans,
             const std::string& tiles){

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

    int numTilePossibilities(string tiles) {

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

}