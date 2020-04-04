//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <vector>

template <class Type>
class QuickSort
{
public:
    QuickSort() = default;
    template<typename Container>
    int partition(Container& vec, int l , int r)
    {
        auto i = l - 1;
        auto pivot = vec[r];

        for(int j = l; j <= r; ++j)
        {
            if(vec[j] < pivot)
            {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }

        std::swap(vec[i + 1], vec[r]);
        return i + 1;
    }

    void recursiveQuickSort(std::vector<Type>& vec, int l, int r)
    {
        if(l < r)
        {
            auto pivot = partition(vec, l, r);
            recursiveQuickSort(vec, l, pivot - 1);
            recursiveQuickSort(vec, pivot + 1, r);
        }
    }

    template<size_t N>
    void recursiveQuickSort(Type(&vec) [N], int l, int r)
    {
        if(l < r)
        {
            auto pivot = partition(vec, l, r);
            recursiveQuickSort(vec, l, pivot - 1);
            recursiveQuickSort(vec, pivot + 1, r);
        }
    }

};

#endif //SORTING_SORTING_H
