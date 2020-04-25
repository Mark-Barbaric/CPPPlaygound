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
  const std::vector<Item> items {{60, 5}, {50, 3}, {70, 4}, {30, 2}};
  Knapsack knapsack(static_cast<int>(items.size()), 5);
  REQUIRE(knapsack.optimumCapacity(items, static_cast<int>(items.size()), 5) == 80);
}
