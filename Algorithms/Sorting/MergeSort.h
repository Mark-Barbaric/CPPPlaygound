//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<typename Type>
class MergeSort
{
public:
    MergeSort() = default;

    void merge(std::vector<Type>& vec, int l , int m , int r)
    {
        auto i = 0, j = 0, k = l;
        auto n1 = m - l + 1;
        auto n2 = r - m;

        std::vector<int> leftArr;
        std::vector<int> rightArr;

        for(i = 0; i < n1; i++)
            leftArr.push_back(vec[l + i]);
        for(j = 0; j < n2; j++)
            rightArr.push_back(vec[m + j + 1]);

        while(i < n1 && j < n2)
        {
            if(leftArr[i] <= rightArr[j])
                vec[k++] = leftArr[i++];
            else
                vec[k++] = rightArr[j++];
        }

        //left over l elements
        while(i < n1)
            vec[k++] = leftArr[i++];

        //left over r elements
        while(j < n2)
            vec[k++] = rightArr[j++];
    }

    void mergeSort(std::vector<Type>& vec, int l, int r)
    {
        if(l < r)
        {
            auto mid = l + (r - l) / 2;
            mergeSort(vec, l, mid);
            mergeSort(vec, mid + 1, r);
            merge(vec, l, mid, r);
        }
    }


};

#endif //SORTING_MERGESORT_H
