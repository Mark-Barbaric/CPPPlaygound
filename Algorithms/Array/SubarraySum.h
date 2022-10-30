#pragma once

#include <unordered_map>

namespace Algorithms::Array{
    inline int MinimumSizeContiguousSubarraySum(std::vector<int>& nums, int s)
    {
        auto l = 0;
        auto sum = 0;
        auto ans = INT_MAX;
        auto count = 0;

        for (auto i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            while (sum >= s)
            {
                int newAns = i + 1 - l;
                ans = std::min(ans, newAns);
                sum -= nums[l++];
                count++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

    inline int SubarraySumEqualsK(std::vector<int>& nums, int s, size_t size)
    {
        auto count = 0;
        auto sum = 0;
        std::unordered_map<int, int> map;
        map[0] = 1;

        for (auto i = 0; i < size; ++i)
        {
            sum += nums[i];
            count += map[sum - s];
            map[sum]++;
        }

        return count;
    }
}