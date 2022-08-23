#pragma once

#include "ScopedTimer.h"

inline void preIncrement(const std::vector<int>& nums){
    MEASURE_FUNCTION();

    for(auto it = nums.begin(); it != nums.end(); ++it){

    }
}

inline void postIncrement(const std::vector<int>& nums){
    MEASURE_FUNCTION();

    for(auto it = nums.begin(); it != nums.end(); it++){

    }
}