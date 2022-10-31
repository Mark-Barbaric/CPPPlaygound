#pragma once
#include <vector>

namespace Algorithms::Array{

    int trappingRainWaterNaive(std::vector<int>& height){

        int total = 0, leftMax = 0, rightMax = 0;

        for(int i = 1; i < height.size() - 1; ++i){

            for(int j = i - 1; j >= 0; --j){
                leftMax = std::max(height[j], leftMax);
            }

            for(int k = i + 1; k < height.size(); ++k){
                rightMax = std::max(height[k], rightMax);
            }

            total += std::min(leftMax, rightMax) - height[i];
        }
        return total;
    }

    int trappingRainWaterDP(std::vector<int>& height){
        std::vector<int> leftMax (height.size(), 0), rightMax(height.size(), 0);

        int total = 0;

        leftMax[0] = height[0];

        for(int i = 1; i < height.size(); ++i){
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        rightMax[rightMax.size() - 1] = height.back();

        for(int i = height.size() - 2; i >= 0; --i){
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        for(int i = 1; i < height.size() - 1; ++i){
            total += std::min(leftMax[i], rightMax[i]) - height[i];
        }

        return total;
    }


}