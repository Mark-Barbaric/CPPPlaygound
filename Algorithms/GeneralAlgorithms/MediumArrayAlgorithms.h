//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef MEDIUMARRAYALGORITHMS_H
#define MEDIUMARRAYALGORITHMS_H

#include "../../Header.h"

namespace MediumArrayAlgorithms
{
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

    inline int MaxProduct(std::vector<int>& nums) {

        auto maxSoFar = nums[0];
        auto minSoFar = nums[0];
        auto res = maxSoFar;

        for (int i = 1; i < nums.size(); ++i)
        {
            auto curr = nums[i];
            auto tempMax = std::max(curr, std::max(maxSoFar * curr, minSoFar * curr));
            minSoFar = std::min(curr, std::min(maxSoFar * curr, minSoFar * curr));
            maxSoFar = tempMax;
            res = std::max(maxSoFar, res);
        }

        return res;
    }

	//Time Complexity O(N) and Space O(N)
    inline std::vector<int> ProductExceptSelf(std::vector<int>& nums) {

        auto index = 0;
        std::vector<int> l(nums.size(), 0), r(nums.size(), 0), ans(nums.size(), 0);

        l[0] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            l[i] = l[i - 1] * nums[i - 1];
        }

        r[nums.size() - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            r[i] = r[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            ans[i] = l[i] * r[i];
        }

        return ans;
    }

    /*
    Kadane Algorithm is used to return the maximum contiguous subarray
    which has the largest sum, and returns this sum.

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Has time complexity of O(n) as array is only cycled over once.
     */
    inline int KadaneMaxSubArray(std::vector<int>& arr)
    {
        if (arr.size() == 0)
            return -1;

        auto currentSum = arr[0];
        auto maxSum = arr[0];

        for (int i = 1; i < arr.size(); ++i)
        {
            currentSum = std::max(arr[i], currentSum + arr[i]);
            maxSum = std::max(currentSum, maxSum);
        }

        return maxSum;
    }

	
}


#endif //BACKTRACKING_MEDIUMARRAYALGORITHMS_H
