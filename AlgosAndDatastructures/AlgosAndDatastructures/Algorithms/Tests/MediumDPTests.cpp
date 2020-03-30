#include "../../catch.hpp"
#include "../DynamicProgramming/NumCombinations.h"

TEST_CASE("Medium DP Tests")
{
	SECTION("Num Combination Tests")
	{
		REQUIRE(num_combinations::numCombinations(12, { 2, 3 ,7 }) == 4);
		REQUIRE(num_combinations::numCombinationsOptimised(12, { 2, 3 ,7 }) == 4);
	}

	SECTION("Vector Combination Tests")
	{
		std::vector<std::vector<int>> response = { {1, 1}, {2} };
		std::vector<std::vector<int>> response2 = { {1, 1, 1}, {1, 2}, {3} };
		REQUIRE(num_combinations::combinationsMatrix(2, { 1, 2}) == response);
		REQUIRE(num_combinations::combinationsMatrix(3, { 1, 2, 3 }) == response2);
	}
}