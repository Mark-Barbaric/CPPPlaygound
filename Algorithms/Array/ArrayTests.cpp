#include <gtest/gtest.h>
#include "FourSum.h"
#include "TrappingWater.h"

namespace Algorithms::ArrayAlgorithms {

    TEST(ArrayAlgorithmTests, FourSumTests) {

    }


    TEST(ArrayAlgorithmTests, TrappingRainWaterTests){
        std::vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
        ASSERT_EQ(trappingRainWaterNaive(h1), 6);
        ASSERT_EQ(trappingRainWaterDP(h1),  6);
    }

}