//
//  SubsetSumAlgorithmTests.cpp
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 28/07/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//

#include <gtest/gtest.h>
#include <ThreeSum.h>

namespace Algorithms::Array::Tests{

    TEST(ArrayAlgorithmTests, TwoSumTests){
        std::vector<int> vec {2, 7, 11, 15};
        std::vector<int> ans = {2, 7};
        ASSERT_EQ(Algorithms::Array::twoSum(vec, 9), ans);
        ASSERT_EQ(Algorithms::Array::twoSumTwo(vec, 9), ans);
    }

    TEST(ArrayAlgorithmTests, ThreeSumTests){
        std::vector<int> v {-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> ans = {{ -1, -1, 2 }, { -1, 0, 1}};
        ASSERT_EQ(Algorithms::Array::threeSum(v), ans);
    }
}
