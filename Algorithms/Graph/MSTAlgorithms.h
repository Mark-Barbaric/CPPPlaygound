#ifndef MST_ALGORITHMS_H
#define MST_ALGORITHMS_H

#include "../../DataStructures/Graph.h"

typedef std::pair<int, std::pair<int, int>> WeightedEdge;

namespace MSTAlgorithms
{
    inline std::vector<int> PrimsMST(const Graph& graph)
	{
        const auto adj = graph.adjacencyMatrix;
        const auto n = adj.size();
        std::vector<int> key(n, LONG_MAX);
        std::vector<bool> inMST(n, false);
        std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, std::greater<std::pair<long, int>>> q;
        q.push({ 0, 1 });
        key[1] = 0;

        while (!q.empty())
        {
            const auto cur = q.top();
            const auto u = cur.second;
            q.pop();

            if (!inMST[u])
            {
                inMST[u] = true;

                for (int v = 1; v < n; ++v)
                {
                    if (adj[u][v] && !inMST[v] && adj[u][v] < key[v])
                    {
                        key[v] = adj[u][v];
                        q.push({ key[v], v });
                    }

                }
            }
        }

        key[0] = 0;
        return key;
	}

    void rankedUnion(int u, int v, std::vector<int>& parent, std::vector<int>& rank)
    {
	    if(rank[u] > rank[v])
	    {
            parent[v] = u;
	    }
        else if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
	
    inline std::vector<int> KruskalsMST(Graph& graph)
	{
        const auto n = graph.adjacencyMatrix.size();
        auto weightedEdgeList = graph.weightedEdgeList;
        std::sort(weightedEdgeList.begin(), weightedEdgeList.end());
        std::vector<int> parent(n, INT_MAX);
		
		for(int i = 1; i < n; ++i)
		{
            parent[i] = i;
		}

        std::vector<int> rank (n, 0);
        std::vector<int> values (2, 0);
        auto sum = 0;
        auto i = 0;
        for (auto it = weightedEdgeList.begin(); it != weightedEdgeList.end(); ++it)
		{
            auto cur = *it;
            const auto weight = cur[0];
            const auto u = cur[1];
            const auto v = cur[2];

            const auto parentU = CycleAlgorithms::unionFind(u, parent);
            const auto parentV = CycleAlgorithms::unionFind(v, parent);

			if(parentU != parentV)
			{
				rankedUnion(parentU, parentV, parent, rank);
                values.push_back(weight);
                sum += weight;
			}
		}

        std::cout << sum << std::endl;
    	
        return values;
	}
	
}



#endif