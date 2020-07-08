//
//  SortingTests.cpp
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 25/04/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//
#include "../../catch.hpp"
#include "../Sorting/SortingAlgorithms.h"
#include "../Sorting/QuickSort.h"
#include "../Sorting/MergeSort.h"

TEST_CASE("Sorting Algorithm Tests")
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
    MergeSort<std::vector<int>> mergeSort;
    mergeSort.mergeSort(arr1, 0, static_cast<int>(arr1.size() - 1));
    REQUIRE(arr1 == sortedArr);
    std::vector<int> arr2 {2, 4, 1, 3, 5};
    const auto count = 3;
    REQUIRE(mergeSort.mergeSortCount(arr2, 0, static_cast<int>(arr2.size() - 1)) == count);
  }
}
