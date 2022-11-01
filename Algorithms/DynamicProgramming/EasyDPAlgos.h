//
// Created by Mark Barbaric on 16/10/2019.
//

#ifndef GREEDY_FINALSCOREALGO_H
#define GREEDY_FINALSCOREALGO_H

#include <vector>
#include <algorithm>
#include <unordered_set>

namespace EasyDynamicProgrammingAlgos
{
	int fibonnacci(std::vector<int>& fibArr, int n)
	{
        if (n <= 0)
            return 0;

		if(n == 1)
            return 1;

        if (fibArr[n] == 0)
        {
            fibArr[n] = fibonnacci(fibArr, n - 1) + fibonnacci(fibArr, n - 2);
        }
		
        return fibArr[n];
	}

	int countPaths(std::vector<std::vector<int>>& grid, int row, int col, std::vector<std::vector<int>> paths)
	{
		if (grid[row][col] == -1)
			return 0;
		if (row == grid.size() - 1 || col == grid.size() - 1)
			return 1;
		if (paths[row][col] == 0)
			paths[row][col] = countPaths(grid, row + 1, col, paths) + countPaths(grid, row, col + 1, paths);

		return paths[row][col];
	}
}






#endif //GREEDY_FINALSCOREALGO_H
