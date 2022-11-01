#include <gtest/gtest.h>
#include <HardSlidingWindow.h>

namespace Algorithms::SlidingWindow::Hard{

    TEST(HardSlidingWindowTests, LongestUniqueSubstringTests){
        std::string s1 = "aabccbb";
        ASSERT_EQ(Algorithms::SlidingWindow::Hard::longestDistinctSubstring(s1), 3);
    }
}