#ifndef CYCLE_AlGORITHMS_H
#define CYCLE_ALGORITHMS_H

#include "Graph.h"

namespace CycleAlgorithms
{
	inline bool containsDirectedCycleUtil(int u, std::vector<bool>& visited, const std::vector<std::list<int>>& adj)
	{
		if (visited[u])
			return true;
		
		visited[u] = true;

		for(auto it = adj[u].begin(); it != adj[u].end(); ++it)
		{
			if (containsDirectedCycleUtil(*it, visited, adj))
				return true;
			
		}

		visited[u] = false;

		return false;
	}
	
	inline bool containsUndirectedCycleUtil(int parent, int u, std::vector<bool>& visited, const std::vector<std::list<int>>& adj)
	{
		visited[u] = true;

		for(auto it = adj[u].begin(); it != adj[u].end(); ++it)
		{
			if(!visited[*it])
			{
				if (containsUndirectedCycleUtil(u, *it, visited, adj))
					return true;
			}
			else if(parent != -1 && *it != parent)
			{
				return true;
			}
		}

		visited[u] = false;

		return false;
	}
	
	inline bool containsCycle(const Graph& graph, bool directed)
	{
		const auto adj = graph.adjacencyList;
		std::vector<bool> visited(adj.size(), false);

		for(int i = 1; i < visited.size(); ++i)
		{
			const auto cycle = directed ? containsDirectedCycleUtil(i, visited, adj) : containsUndirectedCycleUtil(-1, i, visited, adj);
			
			if (cycle)
				return true;
		}
		
		return false;
	}

	inline void unionJoin(int u, int v, std::vector<int>& parent)
	{
		parent[u] = v;
	}

	inline int unionFind(int u, std::vector<int>& parent)
	{
		if(u == parent[u])
		{
			return u;
		}
		else
		{
			return unionFind(parent[u], parent);
		}
	}

	inline bool containsCycleUnionFind(Graph& graph)
	{
		const auto n = graph.adjacencyList.size();
		std::vector<int> parent(n, -1);

		for(int i = 1; i < n; ++i)
		{
			parent[i] = i;
		}
		
		const auto edges = graph.weightedEdgeList;

		for(auto & e : edges)
		{
			const auto u = e[1];
			const auto v = e[2];

			const auto parentU = unionFind(u, parent);
			const auto parentV = unionFind(v, parent);

			if(parentU == parentV)
			{
				return true;
			}

			unionJoin(parentV, parentU, parent);
		}

		return false;
		
	}
	
}



#endif