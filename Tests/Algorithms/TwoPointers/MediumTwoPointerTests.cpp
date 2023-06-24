#include <gtest/gtest.h>
#include <MediumTwoPointer.h>

namespace Algorithms::TwoPointers::Medium::Tests{
    
    TEST(TwoPointerTests, MediumTwoPointerTests){
        std::vector<int> nums1 = {2, 0, 1, 2, 0, 0, 2};
        ASSERT_EQ(Algorithms::TwoPointer::Medium::doubleZeroes(nums1), 4);
        std::vector<int> ans1 = {2, 1, 2, 2, 0, 0, 0};
        ASSERT_EQ(nums1, ans1);
    }
}