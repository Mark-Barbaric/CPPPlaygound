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
        std::cout << u << " ";

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

    void printAdjacencyList()
    {

        for(int i = 0; i < v; ++i)
        {
            std::cout << "\nAdjacency list of vertex " << i << "\n";

            for (auto x : adjacencyList[i])
                std::cout << i << " -> " << x << "\n";

        }

        std::cout << "\n";
    }

    void printMatrix()
    {
        std::cout << "Graph Matrix \n";

        for(int i = 0; i < v; ++i)
        {
            for(int j = 0; j < v; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    };

    void dfs(int start)
    {
        std::cout << "DFS" << "\n";
        std::vector<bool> visited (v, false);
        for(int i = 0; i < v; ++i)
            if(!visited[i])
                dfsUtil(i, visited);

        std::cout << "\n";
        std::cout << "\n";
    }

    void bfs(int start)
    {
        std::cout << "BFS" << "\n";
        std::vector<bool> visited(v, false);
        std::stack<int> s;
        visited[start] = true;
        s.push(start);

        while(!s.empty())
        {
            auto next = s.top();
            s.pop();
            std::cout << next << " ";


            for(auto it = adjacencyList[next].begin(); it != adjacencyList[next].end(); ++it)
            {
                if(!visited[*it])
                {
                    visited[*it] = true;
                    s.push((*it));
                }
            }
        }

        std::cout << "\n";
        std::cout << "\n";

    }


    const int getVertexLength() const {return v;}
    const std::vector<std::vector<int>>& getAdjacencyList() const {return adjacencyList;}



};

#endif //BACKTRACKING_GRAPH_H
