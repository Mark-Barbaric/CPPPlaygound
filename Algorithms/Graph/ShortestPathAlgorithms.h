#ifndef SHORTEST_PATH_ALGORITHMS_H
#define SHORTEST_PATH_ALGORITHMS_H

#include "include/Header.h"
#include "../../DataStructures/Graphs/Graph.h"

namespace ShortestPathAlgorithms
{

	inline int SmallestVertex(std::vector<int>& values, std::vector<bool>& processed)
	{
		int max = INT_MAX, vertex = -1;

		for(int v = 1; v < values.size(); ++v)
		{
			if(!processed[v] && values[v] <= max)
			{
				vertex = v;
				max = values[v];
			}
		}

		return vertex;
	}
	
	inline std::vector<int> DijkstrasShortestPath(Graph& graph, int s)
	{
		const auto n = graph.adjacencyMatrix.size();
		const auto& adjacencyMatrix = graph.adjacencyMatrix;
		std::vector<bool> processed(n, false);
		std::vector<int> values(n, INT_MAX);
		values[s] = 0;

		for(int i = 1; i < n - 1; ++i)
		{
			auto u = SmallestVertex(values, processed);
			processed[u] = true;

			for(int v = 1; v < n; ++v)
			{
				
				if(adjacencyMatrix[u][v] > 0 && !processed[v] && values[u] != INT_MAX && values[u] + adjacencyMatrix[u][v] < values[v])
				{
					values[v] = values[u] + adjacencyMatrix[u][v];
				}
			}
			
		}

		return values;
	}

	inline std::vector<int> OptimisedDijkstrasShortestPath(Graph& graph, int s)
	{
		const auto adj = graph.adjacencyMatrix;
		const auto n = adj.size();

		std::vector<int> values(n, INT_MAX);
		std::vector<bool> processed(n, false);
		std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int,int>>> q;
		q.push(std::make_pair(0, s));
		values[s] = 0;
		
		while(!q.empty())
		{
			const auto cur = q.top();
			q.pop();
			const auto u = cur.second;
			processed[u] = true;

			for(int v = 1; v < n; ++v)
			{
				if(adj[u][v] != 0 && !processed[v] && values[u] != INT_MAX && values[u] + adj[u][v] < values[v])
				{
					values[v] = values[u] + adj[u][v];
					q.push({ values[v], v });
				}
				
			}
		}

		return values;			
		
	}

	
}


#endif
