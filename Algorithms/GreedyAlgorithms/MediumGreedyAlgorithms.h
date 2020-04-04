//
// Created by Mark Barbaric on 29/10/2019.
//

#ifndef BACKTRACKING_MEDIUMGREEDY_H
#define BACKTRACKING_MEDIUMGREEDY_H

template<typename Type, typename Container>
class MediumGreedyAlgorithms
{
public:
    MediumGreedyAlgorithms() = default;

    Type maximumWaterUnderVerticalLines(Container& vec, size_t size)
    {
        int l = 0, r = size - 1;
        Type maxSum = 0;

        while(l < r)
        {
            Type newMax = (r - l) * std::min(vec[l],vec[r]);
            maxSum = std::max(maxSum, newMax);

            if(vec[l] < vec[r])
                l++;
            else
                r--;
        }

        return maxSum;

    }


};

#endif //BACKTRACKING_MEDIUMGREEDY_H
