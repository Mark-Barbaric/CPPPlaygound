//
// Created by Mark Barbaric on 30/10/2019.
//

#ifndef GRAPH_H
#define GRAPH_H

#include "../../Header.h"

class Graph
{
  const int v;
  const bool directed;
  
public:

  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<std::list<int>> adjacencyList;
  std::vector<std::vector<int>> weightedEdgeList;
	
    explicit Graph(const int v_, const bool directed_ = false)
    :v(v_),
	directed(directed_)
     {
        adjacencyMatrix.resize(v, std::vector<int>(v,0));
        adjacencyList.resize(v);
     }

    void addEdge(int u, int v)
    {
      adjacencyList[u].push_back(v);
      adjacencyMatrix[u][v] = 1;
      weightedEdgeList.push_back({ 0, u, v});

      if (!directed)
      {
          adjacencyMatrix[v][u] = 1;
          adjacencyList[v].push_back(u);
      }
    }

	void addEdge(int u, int v, int w)
    {
        adjacencyMatrix[u][v] = w;
        weightedEdgeList.push_back({ w, u, v});

    	if(!directed)
    	{
            adjacencyMatrix[v][u] = w;
    	}
    }
 
};

#endif //BACKTRACKING_GRAPH_H
