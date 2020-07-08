#include "../../catch.hpp"
#include "../DynamicProgramming/EasyDPAlgos.h"

TEST_CASE("Intro Algo Tests")
{
	SECTION("Fibonacci Tests")
	{
		const auto n = 10;
		std::vector<int> fibArr(11, 0);
		REQUIRE(EasyDynamicProgrammingAlgos::fibonnacci(fibArr, n) == 55);
	}
}

TEST_CASE("Count Paths Tests")
{
	std::vector<std::vector<int>> blocks = { {},{2,6},{4},{0,2,5},{2},{3,4,6},{1,5} };
	std::vector<std::vector<int>> grid(8, std::vector<int>(8, 0));

	for(int r = 0; r < blocks.size(); ++r)
	{
		auto blockRow = blocks[r];
		
		for(int c = 0; c < blockRow.size(); ++c)
		{
			auto blockCol = blockRow[c];
			grid[r][blockCol] = -1;
		}
	}
	
	std::vector<std::vector<int>> paths(8, std::vector<int>(8, 0));
	REQUIRE(EasyDynamicProgrammingAlgos::countPaths(grid, 0, 0, paths) == 27);
}