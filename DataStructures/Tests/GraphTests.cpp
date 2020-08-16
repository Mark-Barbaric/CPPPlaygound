#include "../../catch.hpp"
#include "Graph.h"
#include "../Graphs/GraphBFSAlgorithms.h"
#include "../Graphs/GraphIslandAlgos.h"
#include "../Graphs/GraphConnectionAlgorithms.h"

TEST_CASE("Graph Base Functionality Tests")
{
	Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 4);
  
  std::string bfsString = "";
  g.BFS(bfsString);
  REQUIRE(bfsString == "01324");
  std::string dfsString = "";
  g.DFS(dfsString);
  REQUIRE(dfsString == "01243");
}

TEST_CASE("Graph BFS Algorithms")
{
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.addEdge(3, 5);
  
  REQUIRE(GraphBFSAlgorithms::MinimumDistance(0, g.adjacencyList) == 2);
}

TEST_CASE("Graph Island Algorithms")
{
  Graph g(4);
  g.addEdge(0, 0);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 0);
  g.addEdge(2, 2);
  g.addEdge(3, 0);
  g.addEdge(3, 1);
  
  REQUIRE(GraphIslandsAlgos::MaxAreaOfIsland(g.adjacencyMatrix) == 4);
  
}

TEST_CASE("Graph Connection Algorithms")
{
  Graph g (6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(4, 5);
  
  REQUIRE(GraphConnectionAlgorithms::NumConnectedComponents(g.adjacencyList) == 2);
  std::vector<std::vector<int>> connectionAns = {{0, 3}, {4,5}};
}


