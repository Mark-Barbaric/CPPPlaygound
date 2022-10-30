//
//  SortingTests.cpp
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 25/04/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//
#include "include/catch.hpp"
#include "../../../Algorithms/Sorting/QuickSort.h"
#include "../../../Algorithms/DivideAndConquer/MergeSort.h"
#include "../../../Algorithms/DivideAndConquer/BSAlgorithms.h"

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
    std::vector<int> arr1 {2, 1, 3, 1, 2};
    const std::vector<int> sortedArr {1, 1, 2, 2, 3};
    MergeSort<int> mergeSort;
    const auto sortResult = mergeSort.mergeSort(arr1, 0, static_cast<int>(arr1.size() - 1));
    REQUIRE(arr1 == sortedArr);
    const auto count = 4;
    REQUIRE(sortResult == count);
  }
}

TEST_CASE("Divide And Conquery Binary Search Tests")
{
	SECTION("Binary Search")
	{
        const std::vector vec = { 1, 2, 3, 4, 5, 6, 7, 9 };
        REQUIRE(BSAlgorithms::RecursiveBinarySearch(0, vec.size() - 1, 9, vec) == 7);
        REQUIRE(BSAlgorithms::IterativeBinarySearch(9, vec) == 7);
        REQUIRE(BSAlgorithms::RecursiveBinarySearch(0, vec.size() - 1, 8, vec) == -1);
        REQUIRE(BSAlgorithms::IterativeBinarySearch(8, vec) == -1);
	}

	SECTION("Pivoted Binary Search")
	{
        const std::vector<int> arr = { 3, 4, 0, 1, 2 };
        const std::vector<int> arr2 = { 0, 1, 2, 3, 4 };
        REQUIRE(BSAlgorithms::FindPivot(0, arr.size() - 1, arr) == 2);
        REQUIRE(BSAlgorithms::FindPivot(0, arr2.size() - 1, arr2) == 0);
        REQUIRE(BSAlgorithms::PivotedBinarySearch(0, arr.size() - 1, 2, arr) == 4);
        REQUIRE(BSAlgorithms::PivotedBinarySearch(0, arr.size() - 1, 4, arr) == 1);
	}
}
