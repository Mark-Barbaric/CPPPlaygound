//
// Created by Mark Barbaric on 27/09/2019.
//

#ifndef SORTING_MERGESORTCOUNT_H
#define SORTING_MERGESORTCOUNT_H

template<typename Type>
class MergeSortCount
{
public:
    MergeSortCount() = default;

    int merge(std::vector<Type>& vec, int l, int m, int r)
    {
        int i = 0, j = 0, k = l, count = 0;
        auto n1 = m - l + 1;
        auto n2 = r - m;

        std::vector<int> leftArray;
        std::vector<int> rightArray;

        for(int a = 0; a < n1; a++)
            leftArray.push_back(vec[l + a]);
        for(int b = 0; b < n2; b++)
            rightArray.push_back(vec[m + b + 1]);

        while(i < n1 && j < n2)
        {
            if(leftArray[i] <= rightArray[j])
            {
                vec[k++] = leftArray[i++];
            }
            else
            {
                count = count + n1 - i;
                vec[k++] = rightArray[j++];
            }

        }

        while (i < n1)
            vec[k++] = leftArray[i++];

        while (j < n2)
            vec[k++] = rightArray[j++];

        return count;

    }

    int mergeSortCount(std::vector<Type>& vec, int l, int r)
    {
        auto sortCount = 0;
        if(l < r)
        {
            auto mid = l + (r - l) / 2;
            sortCount = mergeSortCount(vec, l, mid);
            sortCount += mergeSortCount(vec, mid + 1, r);
            sortCount += merge(vec, l, mid, r);
        }

        return sortCount;
    }


};

#endif //SORTING_MERGESORTCOUNT_H
