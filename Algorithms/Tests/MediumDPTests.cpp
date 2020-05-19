#include "../../catch.hpp"
#include "../DynamicProgramming/NumCombinations.h"
#include "../DynamicProgramming/Knapsack.h"

TEST_CASE("Score Combination Tests")
{
	SECTION("Num Combination Tests")
	{
    NumCombinations numCombinations(3, 12);
		REQUIRE(numCombinations.numCombinations(12, { 2, 3 ,7 }) == 4);
		REQUIRE(numCombinations.numCombinationsOptimised(12, { 2, 3 ,7 }) == 4);
	}

	SECTION("Score Combination Tests")
	{
    NumCombinations numCombinations(3, 3);
		std::vector<std::vector<int>> response2 = { {1, 1, 1}, {1, 2}, {3} };
		REQUIRE(numCombinations.numCombinationsOutcomes(3, { 1, 2, 3 }) == response2);
	}
}

TEST_CASE("Knapsack Tests")
{
	SECTION("Maximum Value Tests")
	{
		std::vector<knapsack::Item> items = { {6, 5}, {5, 3}, {7, 4}, {3, 2} };
		const auto maxWeight = 5;
		REQUIRE(knapsack::maximumValue(maxWeight, items) == 8);
		REQUIRE(knapsack::maximumValueOptimised(maxWeight, items) == 8);
	}
}
