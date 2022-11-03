#include <gtest/gtest.h>
#include <MediumSlidingWindow.h>

namespace Algorithms::SlidingWindow::Medium{

    TEST(MediumSlidingWindowTests, LongestSubstringTests){
        const std::string s1 = "abac";
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::longestSubstringWithKDistinctCharacters(s1, 3), 4);
        const std::string s2 = "araaci";
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::longestSubstringWithKDistinctCharacters(s2, 2), 4);
        const std::string s3 = "abcac";
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::longestSubstringWithKDistinctCharacters(s3, 2), 3);
        const std::string s4 = "abcacc";
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::longestSubstringWithKDistinctCharacters(s4, 2), 4);
    }

    TEST(MediumSlidingWindowTests, MaxNumberOfFruits){
        
        std::vector<char> trees1 = {'A', 'B', 'C', 'A', 'C'};
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::maxNumberOfFruits(trees1), 3);
    }

    TEST(MediumSlidingWindowTests, MaxConsecutiveOneTests){
        std::vector<int> arr1 = {1,1,1,0,0,0,1,1,1,1,0};
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::maxConsecutiveOnesIII(arr1, 2), 6);
        std::vector<int> arr2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::maxConsecutiveOnesIII(arr2, 3), 10);
    }
}