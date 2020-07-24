#include "../../catch.hpp"
#include "../Graphs/GraphDFSAlgos.h"

TEST_CASE("Graph DFS Tests")
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	SECTION("Num Connected Components Tests")
	{
		REQUIRE(GRAPH_DFS_ALGOS::numConnectedComponents(g.adjacencyList) == 2);
	}

	SECTION("Num Islands Tests")
	{
		std::vector<std::vector<int>> adjacencyMatrix = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
		REQUIRE(GRAPH_DFS_ALGOS::numIslands(adjacencyMatrix) == 3);
		std::vector<std::vector<int>> adjacencyMatrix2 = { {1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,1,1} };
		REQUIRE(GRAPH_DFS_ALGOS::numIslands(adjacencyMatrix2) == 2);
	}
}