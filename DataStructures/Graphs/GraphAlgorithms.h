//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef BACKTRACKING_GRAPHALGORITHMS_H
#define BACKTRACKING_GRAPHALGORITHMS_H

#include "Graph.h"

//class GraphAlgorithms
//{
//
//    Graph& graph;
//
//    bool containsCycle(int v, std::vector<bool>& visited, std::vector<bool>& recursiveStack)
//    {
//        auto vertex = graph.getAdjacencyList();
//        if(!visited[v])
//        {
//            visited[v] = true;
//            recursiveStack[v] = true;
//
//            for(auto it = vertex[v].begin(); it != vertex[v].end(); ++it)
//            {
//                if(!visited[*it] && containsCycle(*it, visited, recursiveStack))
//                    return true;
//                else if(visited[*it])
//                    return true;
//            }
//        }
//
//        visited[v] = false;
//        return false;
//
//    }
//
//public:
//    explicit GraphAlgorithms(Graph& g)
//            :graph(g)
//    {
//
//    }
//
//    int minimumDistance(int u, int v)
//    {
//        auto vertex = graph.getAdjacencyList();
//        std::vector<bool> visited(graph.getVertexLength(), false);
//        std::vector<int> distances(graph.getVertexLength(), 0);
//        std::stack<int> stack;
//
//        while(!stack.empty())
//        {
//
//
//        }
//
//    }
//
//    bool isCyclic(int v)
//    {
//        std::vector<bool> visited(v, false);
//        std::vector<bool> recursiveStack(v, false);
//
//        for(int i = 0; i < v; ++i)
//            if(containsCycle(i, visited, recursiveStack))
//                return true;
//
//        return false;
//    }
//
//};

#endif //BACKTRACKING_GRAPHALGORITHMS_H
