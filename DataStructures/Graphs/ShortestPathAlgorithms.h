#ifndef SHORTEST_PATH_ALGORITHMS_H
#define SHORTEST_PATH_ALGORITHMS_H

#include "../../Header.h"
#include "Graph.h"

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
				std::cout << u << " " << v << " " << adjacencyMatrix[u][v] << std::endl;
				
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
		const auto adjacencyMatrix = graph.adjacencyMatrix;
		const auto n = adjacencyMatrix.size();
		std::vector<bool> processed(n, false);
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>>	queue;
		queue.push(std::make_pair(s - 1, 0));


		for(int i = 0; i < n; ++i)
		{
			auto size = queue.size();

			while(size > 0)
			{
				const auto cur = queue.top();
				const auto u = cur.first;
				const auto dist = cur.second;
				queue.pop();

			}

			
		}
	}

	
}


#endif
