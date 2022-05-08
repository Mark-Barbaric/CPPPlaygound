#ifndef CYCLE_AlGORITHMS_H
#define CYCLE_ALGORITHMS_H

#include "../../DataStructures/Graphs/Graph.h"

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

		for(auto it = adj[u].begin(); it != adj[u].end(); ++it){

			if(!visited[*it]){
				if (containsUndirectedCycleUtil(u, *it, visited, adj))
					return true;
			}
			else if(parent != -1 && *it != parent){
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

		for(int i = 1; i < visited.size(); ++i){

			const auto cycle = directed ? containsDirectedCycleUtil(i, visited, adj) : containsUndirectedCycleUtil(-1, i, visited, adj);
			
			if (cycle)
				return true;
		}
		
		return false;
	}
}

#endif