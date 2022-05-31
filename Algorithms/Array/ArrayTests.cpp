#include <gtest/gtest.h>
#include "FourSum.h"
#include "TrappingWater.h"
#include "ContainsDuplicate.h"

namespace Algorithms::ArrayAlgorithms {

    TEST(ArrayAlgorithmTests, FourSumTests) {

    }


    TEST(ArrayAlgorithmTests, TrappingRainWaterTests){
        std::vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
        ASSERT_EQ(trappingRainWaterNaive(h1), 6);
        ASSERT_EQ(trappingRainWaterDP(h1),  6);
    }

    TEST(ArrayAlgorithms, ContainsDuplicates){
        std::vector<int> nums = {1,4,5,6,7,2,3,11,9,22,33,44,55,66,66};
        ASSERT_TRUE(containsDuplicateSorting(nums));
        ASSERT_TRUE(containsDuplicateMap(nums));
        std::vector<int> nums2 = {1,1,1,3,3,4,3,2,4,2};
        std::cout << "\n";
        ASSERT_TRUE(containsDuplicateSorting(nums2));
        ASSERT_TRUE(containsDuplicateMap(nums2));
    }

}