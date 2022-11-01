
#pragma once
#include <vector>

namespace Algorithms::SlidingWindow::Easy{

    /*
    Smallest Subarray With Greater Sum
    Given an array of positive integers and a number ‘S,’ 
    find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. 
    Return 0 if no such subarray exists.

    Input: [2, 1, 5, 2, 3, 2], S=7
    Output: 2
    Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2].

    Input: [2, 1, 5, 2, 3, 2], S=12
    Output: 0
    Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2].

    Time Complexity
    O(N + N)

    Space Complexity
    O(K)
    
    */

   int smallestSubarraySum(std::vector<int>& nums, int s){

        int windowStart = 0, windowEnd = 0, minLength = static_cast<int>(nums.size()), total = 0;

        for(windowEnd; windowEnd < nums.size(); ++windowEnd){
            total += nums[windowEnd];

            while(windowStart < windowEnd && total >= s){
                minLength = std::min(minLength, windowEnd - windowStart + 1);
                total -= nums[windowStart];
                windowStart += 1;
            }
        }

        if(total < s && minLength == nums.size()){
            return 0;
        }

        return minLength;

   }
}