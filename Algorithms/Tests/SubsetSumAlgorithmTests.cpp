//
//  SubsetSumAlgorithmTests.cpp
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 28/07/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//
#include "../../catch.hpp"
#include "../SubsetSum/SubsetSumAlgorithms.h"

TEST_CASE("Subset Sum Tests")
{
  SECTION("Two Sum Tests")
  {
    std::vector<int> vec {2, 7, 11, 15};
    std::vector<int> ans = {2, 7};
    REQUIRE(SubsetSumAlgorithms::twoSum(vec, 9) == ans);
    REQUIRE(SubsetSumAlgorithms::twoSumTwo(vec, 9) == ans);
  }
  
  SECTION("Three Sum Tests")
  {
    std::vector<int> v {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ans = {{ -1, -1, 2 }, { -1, 1, 0}};
    REQUIRE(SubsetSumAlgorithms::threeSum(v) == ans);
    std::vector<int> v2 {0, 0, 0, 0};
    std::vector<std::vector<int>> ans2 = {{0, 0, 0}};
    REQUIRE(SubsetSumAlgorithms::threeSum(v2) == ans2);
  }
}

