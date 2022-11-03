#include <gtest/gtest.h>
#include <HardSlidingWindow.h>

namespace Algorithms::SlidingWindow::Hard{

    TEST(HardSlidingWindowTests, LongestUniqueSubstringTests){
        std::string s1 = "aabccbb";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestDistinctSubstring(s1), 3);
    }

    TEST(HardSlidingWindowTests, LongestUniqueSubstringWithReplacementTests){
        std::string s1 = "abcaa";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestRepeatingSubstringWithReplacements(s1, 0), 2);
        std::string s2 = "abc";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestRepeatingSubstringWithReplacements(s2, 1), 2);
        std::string s3 = "caa";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestRepeatingSubstringWithReplacements(s3, 1), 3);
        std::string s4 = "aabccbb";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestRepeatingSubstringWithReplacements(s4, 2), 5);
    }
}