#pragma once

namespace Algorithms::Graph{

    inline void unionJoin(int u, int v, std::vector<int>& parent){
        parent[u] = v;
    }

    inline int unionFind(int u, std::vector<int>& parent){

        if(u == parent[u]){
            return u;
        }
        else{
            return unionFind(parent[u], parent);
        }
    }

    inline bool containsCycleUnionFind(Graph& graph){
        const auto n = graph.adjacencyList.size();
        std::vector<int> parent(n, -1);

        for(int i = 1; i < n; ++i){
            parent[i] = i;
        }

        const auto edges = graph.weightedEdgeList;

        for(auto & e : edges)
        {
            const auto u = e[1];
            const auto v = e[2];

            const auto parentU = unionFind(u, parent);
            const auto parentV = unionFind(v, parent);

            if(parentU == parentV){
                return true;
            }

            unionJoin(parentV, parentU, parent);
        }

        return false;
    }
}