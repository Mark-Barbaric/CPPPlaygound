//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef GENERALALGORITHMS_H
#define GENERALALGORITHMS_H

#include <vector>

template<typename Type, typename Container>
class SimpleArrayAlgorithms
{
public:
    SimpleArrayAlgorithms() = default;

    /*
        Simple algorithm which returns the max of an array
    */
    Type maxFromArray(Container& vec, size_t size)
    {
        if(size == 0)
            return -1;

        Type max = vec[0];

        for(int i = 1; i < size; ++i)
        {
            if(vec[i] > max)
                max = vec[i];
        }

        return max;
    }

    /*
    Kadane Algorithm is used to return the maximum contiguous subarray
    which has the largest sum, and returns this sum.

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Has time complexity of O(n) as array is only cycled over once.
     */
    Type maxSubArrayKadane(Container& arr, size_t size)
    {
        if(size == 0)
            return -1;

        Type currentSum = arr[0];
        Type maxSum = arr[0];

        for(int i = 1; i < size; ++i)
        {
            currentSum = std::max(arr[i], currentSum + arr[i]);
            maxSum = std::max(currentSum, maxSum);
        }

        return maxSum;
    }
};

#endif //BACKTRACKING_GENERALALGORITHMS_H
