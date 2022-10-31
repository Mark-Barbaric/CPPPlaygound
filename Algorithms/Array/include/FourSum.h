#pragma once

#include <vector>
#include <algorithm>

namespace Algorithms::Array{

    inline void twoSum(std::vector<int>& nums,
                                        std::vector<std::vector<int>>& ans,
                                        int i, int j, int target){

        int l = i + 1, r = nums.size() - 1;

        while(l < r){
            const auto sum = (nums[i] + nums[j] + nums[l] + nums[r]) - target;

            if(sum > 0){
                r--;
            } else if(sum < 0){
                l++;
            } else {
                ans.push_back({nums[i], nums[j], nums[l++], nums[r--]});

                while(l < r && nums[l] == nums[l-1]){
                    l++;
                }

                while(l < r && nums[r] == nums[r + 1]){
                    r--;
                }
            }
        }
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

        if(nums.size() < 4){
            return {};
        }

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        for(int i = 0; i < nums.size() - 3; ++i){

            for(int j = i + 1; j < nums.size() - 2; ++j){

                const auto total = target - nums[i] - nums[j];

                twoSum(nums, ans, i, j, total);

                while(j < nums.size() - 2 && nums[j] == nums[j + 1]){
                    j++;
                }
            }

            while(i < nums.size() - 3 && nums[i] == nums[i + 1]){
                i++;
            }
        }

        return ans;

    }
}