#include <gtest/gtest.h>
#include "BinarySearch.h"

namespace Algorithms::BinarySearch{

    TEST(BinarySearchTests, Template1Tests){
        std::vector<int> nums {5,7,8,9,11,12};
        ASSERT_EQ(binarySearchTemplate1(nums, 9), 3);
        ASSERT_EQ(binarySearchTemplate1(nums, 13), -1);
    }

    TEST(BinarySearchTests, Template2Tests){
        std::vector<int> peakNums {1,2,3,1};
        ASSERT_EQ(binarySearchTemplate2(peakNums), 2);
        std::vector<int> peakNums2 {7,1,2,3,4,5,6};
        ASSERT_EQ(binarySearchTemplate2(peakNums2), 0);
    }
}