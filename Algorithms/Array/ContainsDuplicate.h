#pragma once
#include <algorithm>
#include <Profiling/ScopedTimer.h>

namespace Algorithms::Array{

    bool containsDuplicateSorting(std::vector<int> nums){
        MEASURE_FUNCTION();
        std::sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }

        return false;
    }

    bool containsDuplicateMap(std::vector<int> nums){
        MEASURE_FUNCTION();

        std::unordered_map<int,int> st;

        for(const auto& n: nums){
            if(st.find(n) != st.end()){
                return true;
            }
            st[n]++;
        }

        return false;
    }
}