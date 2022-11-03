#include <gtest/gtest.h>
#include <EasySlidingWindow.h>
#include <cmath>

namespace Algorithms::SlidingWindow::Easy::Tests{

    TEST(AlgorithmTests, EasySlidingWindowTests){
        std::vector<int> nums = {2, 1, 5, 2, 3, 2};
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::smallestSubarraySum(nums, 7), 2);
        std::vector<int> nums2 = {1,1,1,1};
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::smallestSubarraySum(nums2, 12), 0);
    }

    TEST(EasySlidingWindowTests, GoodSubstringsOfSizeThreeTests){
        const std::string s1 = "xyzzaz";
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::goodSubstringsOfSizeThree(s1), 1);
        const std::string s2 = "aababcabc";
        ASSERT_EQ(Algorithms::SlidingWindow::Easy::goodSubstringsOfSizeThree(s2), 4);
    }

    bool isDoubleClose(double n1, double n2, double epsilon = 0.0001f){
        return std::fabs(n1 - n2) <= epsilon;

    }

    TEST(EasySlidingWindowTests, MaximumAverageSubarrayI){
        std::vector<int> array1 {1, 12, -5, -6, 50, 3};
        ASSERT_TRUE(isDoubleClose(Algorithms::SlidingWindow::Easy::maxAverageSubarrayI(array1, 4), 12.75f));
    }
    
}