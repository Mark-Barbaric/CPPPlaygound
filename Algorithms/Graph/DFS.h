#pragma once
#include <Graph.h>
#include <string>
#include <iostream>

namespace Algorithms::Graph {

    void DFSUtil(int u, int v, Datastructures::DirectedGraph const& g, std::vector<std::vector<int>>& visited, std::string& cur){
        if(visited[u][v] || !g.getMatrix()[u][v]){
            return;
        }
        
        cur += static_cast<char>(v) + '0';
        visited[u][v]=1;

        for(auto it = g.getMatrix()[u].begin(); it != g.getMatrix()[u].end(); ++it){
            DFSUtil(u, *it, g, visited, cur);
        }
    }

    std::string DFS(Datastructures::DirectedGraph const& g){

        std::vector<std::vector<int>> visited(g.numVertices(), std::vector<int>(g.numVertices(), 0));
        std::string ans = "";

        for(int i = 0; i < g.numVertices(); ++i){

            for(int j = 0; j < g.numVertices(); ++j){
                if(!visited[i][j]){
                    DFSUtil(i, j, g, visited, ans);
                }
            }
        }

        return ans;
    }
}