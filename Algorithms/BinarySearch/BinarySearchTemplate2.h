#pragma once
#include "../../include/Header.h"

namespace Algorithms::BinarySearch{

    int findPeakElement(const std::vector<int>& nums){
        int l = 0, r = nums.size() - 1;

        while(l < r){
            const auto m = l + (r - l) / 2;

            if(nums[m + 1] > nums[m]){
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    // 7,6,5,4,3

    // 3,7,6,5,4
    // 3,4,5,6,7
    int minimumInRotatedSortedArray(const std::vector<int>& nums){
        int l = 0, r = nums.size() - 1;

        while(l < r){
            const auto m = l + (r - l) / 2;

            if(nums[m + 1] < nums[m]){
                return m + 1;
            }

            if(nums[m] < nums[0]){
                r = m;
            } else {
                l = m + 1;
            }
        }

        return 0;
    }
}