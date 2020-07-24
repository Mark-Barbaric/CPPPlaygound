#ifndef GRAPH_DFS_ALGOS_H
#define GRAPH_DFS_ALGOS_H

#include "Graph.h"

namespace GRAPH_DFS_ALGOS
{
	inline void dfsUtil(int u, std::vector<std::vector<int>>& adjacencyList, std::vector<bool>& visited)
	{
		visited[u] = true;

		for(auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it)
		{
			if (!visited[*it])
				dfsUtil(*it, adjacencyList, visited);
		}	
	}

	inline int numConnectedComponents(std::vector<std::vector<int>>& adjacencyList)
	{
		const auto v = adjacencyList.size();
		std::vector<bool> visited (v, false);
		int count = 0;
		
		for(int i = 0; i < v; ++i)
		{
			if(!visited[i])
			{
				dfsUtil(i, adjacencyList, visited);
				count++;
			}
		}

		return count;		
	}

	bool isSafe(int r, int c, std::vector<std::vector<int>>& adjacencyMatrix, std::vector<std::vector<bool>>& visited)
	{
		return (r >= 0 && r < adjacencyMatrix.size() && c >= 0 && c < adjacencyMatrix[0].size() && !visited[r][c] && adjacencyMatrix[r][c]);
	}
	
	void dfsUtil(int r, int c, std::vector<std::vector<int>>& adjacencyMatrix, std::vector<std::vector<bool>>& visited)
	{
		if(isSafe(r, c, adjacencyMatrix, visited))
		{
			visited[r][c] = true;
			dfsUtil(r + 1, c, adjacencyMatrix, visited);
			dfsUtil(r - 1, c, adjacencyMatrix, visited);
			dfsUtil(r, c + 1, adjacencyMatrix, visited);
			dfsUtil(r, c - 1, adjacencyMatrix, visited);
		}
		
	}

	inline int numIslands(std::vector<std::vector<int>>& adjacencyMatrix)
	{
		const auto r = adjacencyMatrix.size();

		if (r == 0)
			return 0;

		const auto c = adjacencyMatrix[0].size();

		std::vector <std::vector<bool>> visited(r, std::vector<bool>(c, false));
		auto numIslands = 0;

		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
			{
				if(!visited[i][j] && adjacencyMatrix[i][j])
				{
					dfsUtil(i, j, adjacencyMatrix, visited);
					numIslands++;
				}
			}
		}

		return numIslands;
	}



	
}




#endif
