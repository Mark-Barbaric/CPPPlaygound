#ifndef NUM_COMBINATIONS_H
#define NUM_COMBINATIONS_H

#include <vector>

class NumCombinations
{
	const int finalScore;
	const std::vector<int> scores;
	std::vector<std::vector<int>> numCombinationsTable;
	std::vector<int> optNumCombinationsTable;

	void recursiveCombinationsSearch(const int min, const int target, std::vector<int> temp, std::vector<std::vector<int>>& combinationsMatrix) const;
	
public:

	NumCombinations(const int f,
		const std::vector<int> s);

	~NumCombinations() = default;
	
	const int numCombinations();
	const int numCombinationsOptimised();
	std::vector<std::vector<int>> combinationsMatrix();


};


#endif