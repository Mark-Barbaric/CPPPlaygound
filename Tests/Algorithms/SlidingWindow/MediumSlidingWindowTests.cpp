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
}