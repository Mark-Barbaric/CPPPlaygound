#include "../../catch.hpp"
#include "../Sorting/SortingAlgorithms.h"

TEST_CASE("Heap Sort")
{
	std::vector<int> nums{ 2, 5, 6, 12, 4, 1, 9 };

	SECTION("Max Heap Sort")
	{
		std::vector<int> ans = {12,9, 6, 5,4,2,1 };
		SortingAlgorithms::HeapSort(nums, true);
		REQUIRE(nums == ans);
	}
}

TEST_CASE("Merge Sort Tests")
{
    
    std::vector<int> arr1{ 2, 1, 3, 1, 2 };
    const std::vector<int> ans{ 1, 1, 2, 2, 3 };
	SortingAlgorithms::MergeSort(0, arr1.size() - 1, arr1);
    REQUIRE(arr1 == ans);
    
}