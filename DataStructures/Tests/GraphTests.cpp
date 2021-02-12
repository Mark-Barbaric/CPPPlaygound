#include "../../catch.hpp"
#include "../Graphs/Graph.h"
#include "../Graphs/ShortestPathAlgorithms.h"
#include "../Graphs/CycleAlgorithms.h"
#include "../Graphs/MSTAlgorithms.h"

TEST_CASE("Graph Cycle Algorithm Tests")
{
	SECTION("Undirected Graph Cycle Tests")
	{
        Graph graph(7);
        graph.addEdge(1, 3);
        graph.addEdge(3, 5);
        graph.addEdge(5, 2);
        graph.addEdge(2, 6);

        SECTION("Doesn't contain Cycle")
        {
            REQUIRE(CycleAlgorithms::containsCycle(graph, false) == false);
            REQUIRE(CycleAlgorithms::containsCycleUnionFind(graph) == false);
        }

        SECTION("Contains Cycle")
        {
            graph.addEdge(5, 6);
            REQUIRE(CycleAlgorithms::containsCycle(graph, false) == true);
            REQUIRE(CycleAlgorithms::containsCycleUnionFind(graph) == true);
        }
	}

    SECTION("Directed Graph Cycle Tests")
    {
        Graph graph(7, true);
        graph.addEdge(1, 3);
        graph.addEdge(3, 5);
        graph.addEdge(5, 2);
        graph.addEdge(2, 6);

        SECTION("Doesn't contain Cycle")
        {
            REQUIRE(CycleAlgorithms::containsCycle(graph, true) == false);
            REQUIRE(CycleAlgorithms::containsCycleUnionFind(graph) == false);
        }

        SECTION("Contains Cycle")
        {
            graph.addEdge(6, 5);
            REQUIRE(CycleAlgorithms::containsCycle(graph, true) == true);
            REQUIRE(CycleAlgorithms::containsCycleUnionFind(graph) == true);
        }
    }
}

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
        REQUIRE(ShortestPathAlgorithms::OptimisedDijkstrasShortestPath(graph, 1) == ans);
	}

}

TEST_CASE("MST Tests")
{
    Graph graph(10);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 8, 8);
    graph.addEdge(2, 8, 11);
    graph.addEdge(2, 3, 8);
    graph.addEdge(8, 9, 7);
    graph.addEdge(8, 7, 1);
    graph.addEdge(3, 9, 2);
    graph.addEdge(9, 7, 6);
    graph.addEdge(3, 4, 7);
    graph.addEdge(3, 6, 4);
    graph.addEdge(7, 6, 2);
    graph.addEdge(4, 5, 9);
    graph.addEdge(4, 6, 14);
    graph.addEdge(6, 5, 10);

	
	SECTION("Prims MST Test")
	{
        std::vector<int> mstAns = { 0, 0, 4, 8, 7, 9, 4, 2, 1, 2 };
        REQUIRE(MSTAlgorithms::PrimsMST(graph) == mstAns);
	}

	SECTION("Kruskal MST Test")
	{
        std::vector<int> kruskalsAns = { 0, 0, 1, 2, 2, 4, 4, 7, 8, 9 };
        REQUIRE(MSTAlgorithms::KruskalsMST(graph) == kruskalsAns);
	}
    
}



