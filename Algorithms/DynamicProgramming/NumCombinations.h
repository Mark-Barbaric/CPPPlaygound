#ifndef NUM_COMBINATIONS_H
#define NUM_COMBINATIONS_H

#include <vector>

namespace num_combinations
{
	const inline int numCombinations(const int finalScore, std::vector<int> scores)
	{
		std::vector<std::vector<int>> numCombinationsTable (scores.size(), std::vector<int>(finalScore + 1, 0));
		
		for (int i = 0; i < scores.size(); ++i)
		{
			//only one way to get a score of 0
			numCombinationsTable[i][0] = 1;

			for (int j = 1; j <= finalScore; ++j)
			{
				//take previous calculated work [i - 1]
				const auto withoutThisScore = i > 0 ? numCombinationsTable[i - 1][j] : 0;
				const auto withThisScore = j >= scores[i] ? numCombinationsTable[i][j - scores[i]] : 0;
				numCombinationsTable[i][j] = withThisScore + withoutThisScore;
			}
		}

		return numCombinationsTable.back().back();
	}

	const inline int numCombinationsOptimised(const int finalScore, std::vector<int> scores)
	{
		std::vector<int> numCombinationsVector (finalScore + 1, 0);
		numCombinationsVector[0] = 1;

		for (int i = 0; i < scores.size(); ++i)
		{
			const auto score = scores[i];

			for (int j = score; j <= finalScore; ++j)
			{
				numCombinationsVector[j] += numCombinationsVector[j - score];
			}
		}

		return numCombinationsVector.back();
	}

	inline void recursiveCombinationsSearch(const int min, const int target, std::vector<int> scores, std::vector<int> temp, std::vector<std::vector<int>>& combinationsMatrix)
	{
		if (target == 0)
			combinationsMatrix.push_back(temp);

		for (int i = 0; i < scores.size(); ++i)
		{
			if (target - scores[i] >= 0 && scores[i] >= min)
			{
				temp.push_back(scores[i]);
				recursiveCombinationsSearch(scores[i], target - scores[i], scores, temp, combinationsMatrix);
				temp.pop_back();
			}
		}
	}

	inline std::vector<std::vector<int>> combinationsMatrix(const int finalScore, const std::vector<int> scores) 
	{
		std::vector<std::vector<int>> scoreCombinations;
		std::vector<int> temp;
		recursiveCombinationsSearch(0, finalScore, scores, temp, scoreCombinations);
		return scoreCombinations;
	}
}

#endif