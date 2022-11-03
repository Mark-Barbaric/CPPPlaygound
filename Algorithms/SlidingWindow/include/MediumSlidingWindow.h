#pragma once

#include <string>
#include <unordered_map>

namespace Algorithms::SlidingWindow::Medium{

    /*
    Given a string, find the length of the longest substring in it with no more than K distinct characters.
    Input: String="araaci", K=2
    Output: 4
    Explanation: The longest substring with no more than '2' distinct characters is "araa".
    O(N + N)
    */

    int longestSubstringWithKDistinctCharacters(const std::string& s, int k){

        int windowStart = 0, maxLength = 0;
        std::unordered_map<char,int> charMap;

        for(int windowEnd = 0; windowEnd < s.length(); ++windowEnd){
            const auto rightChar = s[windowEnd];
            charMap[rightChar]++;

            while(charMap.size() > k){
                
                const auto leftChar = s[windowStart];

                charMap[leftChar]--;
                if(charMap[leftChar] == 0){
                    charMap.erase(leftChar);
                }
                
                windowStart++; 
            }

            maxLength = std::max(maxLength, windowEnd - windowStart + 1);               
        }

        return maxLength;
    }

    /*
    You are visiting a farm to collect fruits. The farm has a single row of fruit trees. You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.

    You will be given an array of characters where each character represents a fruit tree. The farm has following restrictions:

    Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
    You can start with any tree, but you can’t skip a tree once you have started.
    You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
    Write a function to return the maximum number of fruits in both baskets.

    Input: Fruit=['A', 'B', 'C', 'A', 'C']
    Output: 3
    Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

    Time Complexity: O(N + N) -> iterate
    Space Complexity: O(3) ->  

    */
    int maxNumberOfFruits(std::vector<char>& fruits){
        int windowStart = 0, windowEnd = 0, maxLength = 1;
        std::unordered_map<char,int> fruitCount;

        for(windowEnd; windowEnd < fruits.size(); ++windowEnd){
            const auto rightChar = fruits[windowEnd];
            fruitCount[rightChar]++;

            while(windowStart <= windowEnd && fruitCount.size() > 2){
                const auto leftChar = fruits[windowStart];
                
                fruitCount[leftChar]--;
                
                if(fruitCount[leftChar] == 0){
                    fruitCount.erase(leftChar);
                }

                windowStart++;
            }

            maxLength = std::max(maxLength, windowEnd - windowStart + 1);

        }

        return maxLength;
    }

    /*
    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
    */
    int maxConsecutiveOnesIII(const std::vector<int>& nums, int k){

        int l = 0, longestSubstring = 0, zeroCount = 0;

        for(int r = 0; r < nums.size(); ++r){
            
            if(nums[r] == 0){
                zeroCount++;
            }

            while(zeroCount > k){
                
                if(nums[l] == 0){
                    zeroCount--;
                }
                
                l++;
            }

            longestSubstring = std::max(r - l + 1, longestSubstring);
        }

        return longestSubstring;
    }

    // https://leetcode.com/problems/max-consecutive-ones-iii/
}