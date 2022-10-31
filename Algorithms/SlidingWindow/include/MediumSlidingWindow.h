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

    int longestSubstringWithKDistinctCharacters(std::string s, int k){

            int windowStart = 0, windowEnd = 0, maxLength = 1;
            std::unordered_map<char,int> charMap;

            for(windowEnd; windowEnd < s.length(); ++windowEnd){
                const auto rightChar = s[windowEnd];
                charMap[rightChar]++;

                while(windowStart < windowEnd && charMap.size() > k){
                    
                    const auto leftChar = s[windowStart];

                    if(charMap[leftChar] == 0){
                        charMap.erase(leftChar);
                    } else {
                        charMap[leftChar]--;
                    }
                    windowStart++; 
                }

                maxLength = std::max(maxLength, windowEnd - windowStart + 1);               
            }

        return maxLength;
    }
}