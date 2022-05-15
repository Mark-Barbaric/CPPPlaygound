#include "include/catch.hpp"
#include "../GeneralAlgorithms/DailyProblems.h"

TEST_CASE("Batch 1")
{
	std::vector<int> arr = { 10, 15, 3, 7 };
	std::vector<int> arr2 = { 10, 15, 3, 7 };
	std::vector<int> arr3 = { 10, 14, 3, 7 };
	REQUIRE(DailyProblems::ArraySum(arr, 17) == true);
	REQUIRE(DailyProblems::ArraySumOptimised(arr, 17) == true);


	std::vector<int> arr4 = { 9, 11, 8, 5, 7, 10 };
	REQUIRE(DailyProblems::GetStockProfit(arr4) == 5);
	std::vector<long> arr5 = { 20, 7, 8, 2, 5 };
	REQUIRE(DailyProblems::minimumLoss(arr5) == 2);
	
}