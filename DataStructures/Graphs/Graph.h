//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef GRAPH_H
#define GRAPH_H

#include "../../Header.h"

class Graph
{
  const int v;
  
  void DFSUtil(int u, std::vector<bool>& visited, std::string& s)
  {
    s += std::to_string(u);
    visited[u] = true;
    
    for(auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it)
    {
      if(!visited[*it])
      {
        visited[*it];
        DFSUtil(*it, visited, s);
      }
    }
  }
  
  void BFSUtil(int u, std::vector<bool>& visited, std::string& s)
  {
    std::list<int> queue;
    queue.push_back(u);
    visited[u] = true;
    
    while(!queue.empty())
    {
      const auto w = queue.front();
      queue.pop_front();
      s += std::to_string(w);
      
      for(auto it = adjacencyList[w].begin(); it != adjacencyList[w].end(); ++it)
      {
        if(!visited[*it])
        {
          visited[*it] = true;
          queue.push_back(*it);
        }
      }
    }
  }

public:

  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<std::list<int>> adjacencyList;
  std::vector<bool> visited;
	
    explicit Graph(const int v_)
    :v(v_)
     {
        adjacencyMatrix.resize(v, std::vector<int>(v,0));
        adjacencyList.resize(v);
        visited.resize(v, false);
     }

    void addEdge(int w, int u)
    {
      adjacencyList[w].push_back(u);
      adjacencyList[u].push_back(w);
      adjacencyMatrix[w][u] = 1;
    }
  
  void BFS(std::string& s)
  {
    std::fill(visited.begin(), visited.end(), false);
    BFSUtil(0, visited,s );
  }
  
  void DFS(std::string& s)
  {
    std::fill(visited.begin(), visited.end(), false);
    
    for(int i = 0; i < v; ++i)
    {
      if(!visited[i])
      {
        DFSUtil(i, visited, s);
      }
    }
  }
  
};

#endif //BACKTRACKING_GRAPH_H
