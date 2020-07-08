//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef BACKTRACKING_GRAPH_H
#define BACKTRACKING_GRAPH_H

#include <vector>
#include <iostream>
#include <stack>

class Graph
{

    std::vector<std::vector<int>> adjacencyList;
    std::vector<std::vector<int>> matrix;
    const int v;

    void updateAdjacencyList(int w, int u)
    {
        adjacencyList[w].push_back(u);
        adjacencyList[u].push_back(w);
    }

    void updateMatrix(int w, int u) {
        matrix[w][u] = 1;
        matrix[u][w] = 1;
    }

    void dfsUtil(int u, std::vector<bool>& visited)
    {
        visited[u] = true;

        for(int i = 0; i < adjacencyList[u].size(); ++i)
            if(!visited[adjacencyList[u][i]])
                dfsUtil(adjacencyList[u][i], visited);
    }

public:

    explicit Graph(const int v_)
    :v(v_)
     {
         adjacencyList.resize(v);
         matrix.resize(v);

         for(int i = 0; i < v; ++i)
             matrix[i].resize(v);
     }


    void addEdge(int w, int u)
    {
        updateAdjacencyList(w, u);
        updateMatrix(w, u);
    }

    void dfs(int start)
    {
        std::vector<bool> visited (v, false);
        for(int i = 0; i < v; ++i)
        {
            if (!visited[i])
                dfsUtil(i, visited);
        }
    }

    void bfs(int start)
    {
        std::vector<bool> visited(v, false);
        std::stack<int> s;
        visited[start] = true;
        s.push(start);

        while(!s.empty())
        {
            const auto next = s.top();
            s.pop();

            for(auto it = adjacencyList[next].begin(); it != adjacencyList[next].end(); ++it)
            {
                if(!visited[*it])
                {
                    visited[*it] = true;
                    s.push((*it));
                }
            }
        }
    }

};

#endif //BACKTRACKING_GRAPH_H
