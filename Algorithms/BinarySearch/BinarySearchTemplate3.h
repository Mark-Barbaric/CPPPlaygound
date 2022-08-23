#pragma once

#include "../../include/Header.h"

namespace Algorithm::BinarySearch{

    int searchRange(const std::vector<int>& nums){
        int l = 0, r = nums.size() - 1;

        while(l + 1 < r){
            const auto m = l + (r - l) / 2;
        }
    }
}