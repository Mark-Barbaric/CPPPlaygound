#include <gtest/gtest.h>
#include <SlidingWindowEasy.h>

namespace Algorithms::SlidingWindow::Easy::Tests{

    TEST(AlgorithmTests, EasySlidingWindowTests){
        std::vector<int> nums = {2, 1, 5, 2, 3, 2};
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::smallestSubarraySum(nums, 7), 2);
    }
    
}