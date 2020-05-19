#include "../../catch.hpp"
#include "../DynamicProgramming/NumCombinations.h"
#include "../DynamicProgramming/Knapsack.h"

TEST_CASE("Score Combination Tests")
{
	SECTION("Num Combination Tests")
	{
		REQUIRE(num_combinations::numCombinations(12, { 2, 3 ,7 }) == 4);
		REQUIRE(num_combinations::numCombinationsOptimised(12, { 2, 3 ,7 }) == 4);
	}

	SECTION("Score Combination Tests")
	{
		std::vector<std::vector<int>> response = { {1, 1}, {2} };
		std::vector<std::vector<int>> response2 = { {1, 1, 1}, {1, 2}, {3} };
		REQUIRE(num_combinations::combinationsMatrix(2, { 1, 2}) == response);
		REQUIRE(num_combinations::combinationsMatrix(3, { 1, 2, 3 }) == response2);
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