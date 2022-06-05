#include <gtest/gtest.h>
#include "BinarySearch.h"
#include "BinarySearchTemplate2.h"
#include "BinarySearchTemplate3.h"

namespace Algorithms::BinarySearch{

    TEST(BinarySearchTests, Template1Tests){
        std::vector<int> nums {5,7,8,9,11,12};
        ASSERT_EQ(binarySearchTemplate1(nums, 9), 3);
        ASSERT_EQ(binarySearchTemplate1(nums, 13), -1);
    }

    TEST(BinarySearchTests, Template2Tests){
        std::vector<int> peakNums {1,2,3,1};
        ASSERT_EQ(findPeakElement(peakNums), 2);
        std::vector<int> peakNums2 {7,1,2,3,4,5,6};
        ASSERT_EQ(findPeakElement(peakNums2), 6);
        std::vector<int> rotatedArray1 {3,4,5,1,2};
        ASSERT_EQ(minimumInRotatedSortedArray(rotatedArray1), 3);
        std::vector<int> rotatedArray2 {4,5,6,7,8,1,2};
        ASSERT_EQ(minimumInRotatedSortedArray(rotatedArray2), 5);
        std::vector<int> rotatedArray3 {1,2,3,4,5};
        ASSERT_EQ(minimumInRotatedSortedArray(rotatedArray3), 0);
    }

    TEST(BinarySearchTests, PowerTests){
        ASSERT_EQ(myPowBinarySearch(2.0,21), std::pow(2.0, 21));
        ASSERT_EQ(myPowLinear(2.0,21), std::pow(2.0, 21));
    }

}