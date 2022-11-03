
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

   /*
    A string is good if there are no repeated characters.
    Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
    Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
    A substring is a contiguous sequence of characters in a string.

    Input: s = "xyzzaz"
    Output: 1
    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
    The only good substring of length 3 is "xyz".

   */

    int goodSubstringsOfSizeThree(const std::string& s){
        int l = 0, count = 0;
        int charCount[26];
        std::fill(std::begin(charCount), std::end(charCount), 0);

        for(int r = 0; r < s.length(); ++r){
            const int rightChar = s[r] - 'a';
            charCount[rightChar]++;

            while(charCount[rightChar] > 1){
                charCount[s[l] - 'a']--;
                l++;
            }

            if((r - l + 1) == 3){
                count++;
                charCount[s[l] - 'a']--;
                l++;
            }
        }

        return count;
    }

    /*
    You are given an integer array nums consisting of n elements, and an integer k.
    Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
    Any answer with a calculation error less than 10-5 will be accepted.

    Input: nums = [1,12,-5,-6,50,3], k = 4
    Output: 12.75000
    Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
    
    */

    double maxAverageSubarrayI(std::vector<int>& nums, int k){
        double maxAverage = std::numeric_limits<double>::min(), total = 0.0;

        for(int r = 0; r < nums.size(); ++r){
            const auto curNum = nums[r];
            total += static_cast<double>(curNum);

            if(r >= (k - 1)){
                const auto curDouble = total / static_cast<double>(k);
                maxAverage = std::max(curDouble, maxAverage);
                const auto leftNum = nums[r - k + 1];
                total -= static_cast<double>(leftNum);
            }
        }

        return maxAverage;
    }

}