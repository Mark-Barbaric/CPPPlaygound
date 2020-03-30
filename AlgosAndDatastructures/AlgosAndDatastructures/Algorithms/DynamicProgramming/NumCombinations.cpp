#include "NumCombinations.h"

NumCombinations::NumCombinations(const int finalScore_,
	const std::vector<int> scores_)
	:finalScore(finalScore_),
	scores(scores_)
{
	numCombinationsTable.resize(scores.size());
	
	for(auto& item : numCombinationsTable)
	{
		item.resize(finalScore + 1);
		std::fill(item.begin(), item.end(), 0);
	}
	optNumCombinationsTable.resize(finalScore + 1);
	std::fill(optNumCombinationsTable.begin(), optNumCombinationsTable.end(), 0);
}

//private methods

const int NumCombinations::numCombinations()
{
	for(int i = 0; i < scores.size(); ++i)
	{
		//only one way to get a score of 0
		numCombinationsTable[i][0] = 1;

		for(int j = 1; j <= finalScore; ++j)
		{
			//take previous calculated work [i - 1]
			const auto withoutThisScore = i > 0 ? numCombinationsTable[i - 1][j] : 0;
			const auto withThisScore = j >= scores[i] ? numCombinationsTable[i][j - scores[i]] : 0;
			numCombinationsTable[i][j] = withThisScore + withoutThisScore;
		}
	}

	return numCombinationsTable.back().back();
}

const int NumCombinations::numCombinationsOptimised()
{
	optNumCombinationsTable[0] = 1;

	for(int i = 0; i < scores.size(); ++i)
	{
		const auto score = scores[i];

		for(int j = score; j <= finalScore; ++j)
		{
			optNumCombinationsTable[j] += optNumCombinationsTable[j - score];
		}
	}
	
	return optNumCombinationsTable.back();
}

void NumCombinations::recursiveCombinationsSearch(const int min, const int target, std::vector<int> temp, std::vector<std::vector<int>>& combinationsMatrix) const
{
	if (target == 0)
		combinationsMatrix.push_back(temp);

	for (int i = 0; i < scores.size(); ++i)
	{
		if (target - scores[i] >= 0 && scores[i] >= min)
		{
			temp.push_back(scores[i]);
			recursiveCombinationsSearch(scores[i], target - scores[i], temp, combinationsMatrix);
			temp.pop_back();
		}
	}
}

std::vector<std::vector<int>> NumCombinations::combinationsMatrix() const
{
	std::vector<std::vector<int>> scoreCombinations;
	std::vector<int> temp;
	recursiveCombinationsSearch(0, finalScore, temp, scoreCombinations);
	return scoreCombinations;
}