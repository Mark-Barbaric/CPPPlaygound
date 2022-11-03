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
        std::unordered_map<char,int> charCount;
      //  std::fill(std::begin(charCount), std::end(charCount), 0);

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

    /*
    Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, 
    find the length of the longest substring having the same letters after replacement.
    Input: String="aabccbb", k=2
    Output: 5
    Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".
    */

    int longestRepeatingSubstringWithReplacements(const std::string& s, int k){

        int l = 0, longestSubstring = 0, maxRepeating = 0;
        int charMap[26];
        std::fill(std::begin(charMap), std::end(charMap), 0);

        for(int r = 0; r < s.length(); ++r){

            const auto rightChar = s[r];
            int charInt = rightChar - 'a';
            charMap[charInt]++;

            maxRepeating = std::max(maxRepeating, charMap[charInt]);

            if((r - l + 1) - maxRepeating > k){
                const auto leftChar = s[l];
                int charInt = leftChar - 'a';
                charMap[charInt]--;
                l++;
            }

            longestSubstring = std::max(longestSubstring, r - l + 1);
        }

        return longestSubstring;

    }
}