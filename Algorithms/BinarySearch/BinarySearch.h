#pragma once
#include "../../include/Header.h"

namespace Algorithms::BinarySearch{
    // https://leetcode.com/problems/frequency-of-the-most-frequent-element/
    int binarySearchTemplate1(const std::vector<int>& nums, int target){

        int l = 0, r = nums.size() - 1;

        while(l <= r){
            const auto m = l + (r - l) / 2;

            if(nums[m] == target){
                return m;
            }

            if(target > nums[m]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
}