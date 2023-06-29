//
// Created by Mark Barbaric on 30/10/2019.
//

#pragma once
#include <vector>
#include <list>
#include <cassert>

namespace Datastructures {

  class DirectedGraph {
    const unsigned int m_vertices;
    std::vector<std::vector<int>> m_matrix;
    public:

      DirectedGraph(const unsigned int v):m_vertices(v)
      {
        m_matrix.resize(m_vertices, std::vector<int>(m_vertices, 0));
      }

      void addEdge(int u, int v){
        assert(u < m_vertices && v < m_vertices);
        m_matrix[u][v] = 1;
      }

      int valueAt(int u, int v) const noexcept{
        return m_matrix[u][v];
      }

      std::vector<std::vector<int>> const& getMatrix() const noexcept {return m_matrix;}

      int numVertices() const noexcept {return m_vertices;}

  };

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
}