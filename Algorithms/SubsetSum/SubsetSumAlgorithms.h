//
//  SubsetSumAlgorithms.h
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 28/07/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//

#ifndef SubsetSumAlgorithms_h
#define SubsetSumAlgorithms_h

#include <vector>
#include <algorithm>

namespace SubsetSumAlgorithms
{

  std::vector<int> twoSum(std::vector<int>& vec, int target)
  {
    std::map<int, int> m;
    
    for(int i = 0; i < vec.size(); ++i)
      m[vec[i]] = i;
    
    for(int i = 0; i < vec.size(); ++i)
    {
      const auto diff = target - vec[i];
      
      if(m.find(diff) != m.end() && m[diff] != i)
      {
        return {vec[i], diff};
      }
    }
    return {};
  }

  std::vector<int> twoSumTwo(std::vector<int>& vec, int target)
  {
    auto l = 0;
    auto r = vec.size() - 1;
    
    while(l < r)
    {
      const auto sum = vec[l] + vec[r];
      
      if(sum == target)
        return {vec[l], vec[r]};
  
      else if(sum < target)
        l++;
      
      else
        r--;
      
    }
    
    return {};
  }

  void twoSumTwo(std::vector<int>& nums, int i, std::vector<std::vector<int>>& res)
  {
    auto l = i + 1;
    auto r = nums.size() - 1;
    
    while(l < r)
    {
      const auto sum = nums[i] + nums[l] + nums[r];
      
      if(sum < 0 || (l > i + 1 && nums[l] == nums[l - 1]))
      {
        ++l;
      }
      
      else if(sum > 0 || (r < nums.size() - 1 && nums[r] == nums[r + 1]))
      {
        --r;
      }
      else
      {
        res.push_back({nums[i], nums[l++], nums[r++]});
      }
      
    }
    
  }

  std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
  {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    
    for(int i = 0; i < nums.size() && nums[i] <= 0; ++i)
      if(i == 0 || nums[i - 1] != nums[i])
        twoSumTwo(nums, i, ans);
  
    return ans;
  }
  

}

#endif /* SubsetSumAlgorithms_h */
