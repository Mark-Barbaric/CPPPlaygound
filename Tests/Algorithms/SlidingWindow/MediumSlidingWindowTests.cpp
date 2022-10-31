#include <gtest/gtest.h>
#include <MediumSlidingWindow.h>

namespace Algorithms::SlidingWindow::Medium{

    TEST(AlgorithmTests, MediumSlidingWindowTests){
        const std::string s1 = "araaci";
        ASSERT_EQ(Algorithms::SlidingWindow::Medium::longestSubstringWithKDistinctCharacters(s1, 2), 4);
    }
}