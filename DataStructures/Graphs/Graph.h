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
	
    explicit Graph(const int v_, const bool directed_ = false)
    :v(v_),
	directed(directed_)
     {
        adjacencyMatrix.resize(v, std::vector<int>(v,0));
        adjacencyList.resize(v);
     }

    void addEdge(int w, int u)
    {
      adjacencyList[w].push_back(u);
      adjacencyMatrix[w][u] = 1;

      if (!directed)
      {
          adjacencyMatrix[u][w] = 1;
          adjacencyList[u].push_back(w);
      }
    }

	void addEdge(int u, int v, int w)
    {
        adjacencyMatrix[u][v] = w;

    	if(!directed)
			adjacencyMatrix[v][u] = w;
    }
 
};


class WeightedGraph : public Graph
{

public:
    WeightedGraph(int n) :Graph(n)
    {

    }

};

#endif //BACKTRACKING_GRAPH_H
