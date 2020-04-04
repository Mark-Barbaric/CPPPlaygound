//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef MEDIUMARRAYALGORITHMS_H
#define MEDIUMARRAYALGORITHMS_H

#include <vector>
#include <iostream>
#include <unordered_map>

template<typename Type, typename Container>
class MediumArrayAlgorithms
{
public:
    MediumArrayAlgorithms() = default;

    //O(n logN) solution which traverses the array and then runs a which loop.
    Type minimumSizeContiguousSubarraySum(Container& nums, Type s, size_t size)
    {
        auto l = 0;
        auto sum = 0;
        auto ans = INT_MAX;
        auto count = 0;

        for(auto i = 0; i < size; ++i)
        {
            sum += nums[i];

            while(sum >= s)
            {
                int newAns = i + 1 - l;
                ans = std::min(ans, newAns);
                sum -= nums[l++];
                count++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

    Type subarraySumEqualsK(Container& nums, Type s, size_t size)
    {
        auto count = 0;
        auto sum = 0;
        std::unordered_map<int,int> map;
        map[0] = 1;

        for(auto i = 0; i < size; ++i)
        {
            sum += nums[i];
            count += map[sum - s];
            map[sum]++;
        }

        return count;
    }

};


#endif //BACKTRACKING_MEDIUMARRAYALGORITHMS_H
