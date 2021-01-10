#include "../../catch.hpp"
#include "../Graphs/Graph.h"
#include "../Graphs/GraphBFSAlgorithms.h"
#include "../Graphs/GraphIslandAlgos.h"
#include "../Graphs/GraphConnectionAlgorithms.h"
#include "../Graphs/ShortestPathAlgorithms.h"

TEST_CASE("Shortest Path Algorithm Tests")
{
	SECTION("Dijkstra's Shortest Path")
	{
        Graph graph(6);
        graph.addEdge(1, 2, 5);
        graph.addEdge(2, 3, 6);
        graph.addEdge(3, 4, 2);
        graph.addEdge(1, 3, 15);
        graph.addEdge(5, 5, 0);

        std::vector<int> ans = { INT_MAX, 0, 5, 11, 13, INT_MAX};

        REQUIRE(ShortestPathAlgorithms::DijkstrasShortestPath(graph, 1) == ans);
	}
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


