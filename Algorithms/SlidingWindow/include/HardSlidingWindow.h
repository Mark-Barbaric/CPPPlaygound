#pragma once
#include <string>
#include <unordered_map>

namespace Algorithms::SlidingWindow::Hard{

    /*
    Given a string, find the length of the longest substring, which has all distinct characters.

    Input: String="aabccbb"
    Output: 3
    Explanation: The longest substring with distinct characters is "abc".
    
    Time Complexity: O(N + N)
    Space Complexity: O(N) or O(1) if fixed size Map is used
    */

    int longestDistinctSubstring(const std::string& s){

        int windowStart = 0, longestSubstring = 0;
        int charCount[26];

        for(int windowEnd = 0; windowEnd < s.length(); ++windowEnd){
            const auto rightChar = s[windowEnd];
            charCount[rightChar]++;

            while(charCount[rightChar] > 1){
                const auto leftChar = s[windowStart];
                charCount[leftChar]--;
                windowStart++;
            }

            longestSubstring = std::max(longestSubstring, windowEnd - windowStart + 1);

        }

        return longestSubstring;
    }
}