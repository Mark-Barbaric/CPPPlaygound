#include "../../../../Catch2/single_include/catch2/catch.hpp"
#include "../DynamicProgramming/NumCombinations.h"

TEST_CASE("Medium DP Tests")
{
	SECTION("Num Combination Tests")
	{
		NumCombinations numCombinations(12, { 2, 3 ,7 });
		REQUIRE(numCombinations.numCombinations() == 4);
		REQUIRE(numCombinations.numCombinationsOptimised() == 4);
		
	}
}