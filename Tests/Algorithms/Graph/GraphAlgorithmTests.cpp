#include <Graph.h>
#include <DFS.h>
#include <vector>
#include <gtest/gtest.h>

namespace Algorithms::Graph{
    
    Datastructures::DirectedGraph GraphFromMatrix(std::vector<std::vector<int>> const& m)
    {
        Datastructures::DirectedGraph newGraph(m.size());
        for(auto i = 0; i < m.size(); ++i){
            for (auto j = 0; j < m[i].size(); ++j){
                if(m[i][j]){
                    newGraph.addEdge(i, j);
                }
            }
        }

        return newGraph;
    }

    TEST(GraphAlgorithmTests, DFSTests)
    {
        std::vector<std::vector<int>> m = {{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},{0,0,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
        const auto newGraph = GraphFromMatrix(m);
        const auto dfsResult = DFS(newGraph);
        EXPECT_EQ(dfsResult, "12345");
    }
}
