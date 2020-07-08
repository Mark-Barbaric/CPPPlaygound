//
//  SortingTests.cpp
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 25/04/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//
#include "../../catch.hpp"
#include "../DivideAndConquer/QuickSort.h"
#include "../DivideAndConquer/MergeSort.h"
#include "../DivideAndConquer/BSAlgorithms.h"

TEST_CASE("Divide And Conquery Sorting Tests")
{
  SECTION("Quick Sort Tests")
  {
    std::vector<int> arr1 {10, 80, 30, 90, 40, 50, 70};
    const std::vector<int> sortedArr {10, 30, 40, 50, 70, 80, 90};
    QuickSort<std::vector<int>> quickSort;
    quickSort.recursiveQuickSort(arr1, 0, static_cast<int>(arr1.size() - 1));
    REQUIRE(arr1 == sortedArr);
  }
  
  SECTION("Merge Sort Tests")
  {
    std::vector<int> arr1 {12, 11, 13, 5, 6, 7};
    const std::vector<int> sortedArr {5, 6, 7, 11, 12, 13};
    MergeSort<int> mergeSort;
    const auto sortResult = mergeSort.mergeSort(arr1, 0, static_cast<int>(arr1.size() - 1));
    REQUIRE(arr1 == sortedArr);
    const auto count = 10;
    REQUIRE(sortResult == count);
  }
}

TEST_CASE("Divide And Conquery Binary Search Tests")
{
	SECTION("Search")
	{
        const std::vector vec = { 1, 2, 3, 4, 5, 6, 7, 9 };
        REQUIRE(BS_Algorithms::binarySearch(0, vec.size() - 1, 9, vec) == 7);
		
	}
}
