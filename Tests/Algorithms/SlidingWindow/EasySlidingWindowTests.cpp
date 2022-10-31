#include <gtest/gtest.h>
#include <EasySlidingWindow.h>

namespace Algorithms::SlidingWindow::Easy::Tests{

    TEST(AlgorithmTests, EasySlidingWindowTests){
        std::vector<int> nums = {2, 1, 5, 2, 3, 2};
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::smallestSubarraySum(nums, 7), 2);
        std::vector<int> nums2 = {1,1,1,1};
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::smallestSubarraySum(nums2, 12), 0);
    }
    
}