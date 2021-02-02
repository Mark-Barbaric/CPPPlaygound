#include "../../catch.hpp"
#include "../Graphs/Graph.h"
#include "../Graphs/ShortestPathAlgorithms.h"
#include "../Graphs/CycleAlgorithms.h"

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
        }

        SECTION("Contains Cycle")
        {
            graph.addEdge(5, 6);
            REQUIRE(CycleAlgorithms::containsCycle(graph, false) == true);
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
        }

        SECTION("Contains Cycle")
        {
            graph.addEdge(6, 5);
            REQUIRE(CycleAlgorithms::containsCycle(graph, true) == true);
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
	}

    SECTION("Negative Weight Dijkstra's Shortest Path")
    {
        Graph graph(4);
        graph.addEdge(1, 2, 3);
        graph.addEdge(2, 3, -2);
        graph.addEdge(1, 3, 2);

        std::vector<int> ans = { INT_MAX, 0, 3, 2};

        REQUIRE(ShortestPathAlgorithms::DijkstrasShortestPath(graph, 1) == ans);
    }
}





