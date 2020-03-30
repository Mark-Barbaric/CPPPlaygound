//
// Created by Mark Barbaric on 29/10/2019.
//

#ifndef BACKTRACKING_SIMPLEGREEDY_H
#define BACKTRACKING_SIMPLEGREEDY_H

#include <iostream>
#include <unordered_set>
#include <string>

template<typename Type, typename Container>
class SimpleGreedyAlgorithms
{
public:
    SimpleGreedyAlgorithms() = default;


    int getChangeBruteForce(Type change, Container& vec, size_t size)
    {
        int count = 0;
        while(change > 0)
        {

            for(int i = 0; i < size; ++i)
            {
                if(vec[i] <= change)
                {
                    change -= vec[i];
                    count++;
                    break;
                }
            }
        }

        return count;

    }

    Type getChangeOptimised(Type change, Container& vec, size_t size)
    {
        int count = 0;

        for(int i = 0; i < size; ++i)
        {
            count += change / vec[i];
            change %= vec[i];
        }

        return count;

    }

    int bruteForceMaximumSubstringLength(std::string s)
    {
        auto maxCount = INT_MIN;

        for(int i = 0; i < s.length() - 1; ++i)
        {
            std::unordered_set<char> set;
            set.insert(s[i]);
            auto newCount = 1;

            for(int j = i + 1; i < s.length(); ++j)
            {

                if(set.count(s[j]) == 0)
                    newCount++;
                else
                {
                    maxCount = std::max(maxCount, newCount);
                    break;
                }

                set.insert(s[j]);
            }

        }

        return maxCount;
    }

    bool isPalindrome(Type s)
    {

        if(s.length() == 1)
            return true;

        Type r;

        for(int i = s.length() - 1; i >= 0; --i)
        {
            r += s[i];
        }

        return s == r;
    }

    Type longestPalindromicSubstring(Type s)
    {
        auto maxCount = 0;
        Type chosenString;
        for(int i = 0; i < s.length(); ++i)
        {
            for(int j = i; j <= s.length(); ++j)
            {
                auto newS = s.substr(i, j);

                if(isPalindrome(newS) && newS.length() > maxCount)
                {
                    maxCount = newS.length();
                    chosenString = newS;
                }

            }
        }
        return chosenString;
    }



    int optimisedMaximumSubstring(std::string s)
    {
        auto n = s.length();
        auto i = 0, j = 0;
        std::unordered_set<char> set;
        auto count = 0;

        while (i < n && j < n)
        {
            if(set.count(s[i]) == 0)
            {
                set.insert(s[i++]);
                count = std::max(count, i - j);
            }
            else
                set.erase(s[j++]);

        }

        return count;

    }



};



#endif //BACKTRACKING_SIMPLEGREEDY_H
