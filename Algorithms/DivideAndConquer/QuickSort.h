//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <vector>
#include <algorithm>

template <typename Container>
class QuickSort
{
  
  int partition(Container& vec, int l, int r)
  {
    auto i = l - 1;
    const auto pivot = vec[r];
    
    for(int j = l; j <= r - 1; ++j)
    {
      if(vec[j] < pivot)
      {
        i++;
        std::swap(vec[i], vec[j]); //swap everything less than pivot
      }
    }
    
    std::swap(vec[i + 1], vec[r]); // restore the pivot to the correct position
    return (i + 1);
  }
  
public:
  QuickSort() = default;

  void recursiveQuickSort(Container& vec, int l, int r)
  {
    if(l < r)
    {
      const auto pi = partition(vec, l, r);
      recursiveQuickSort(vec, l, pi - 1); //before pi
      recursiveQuickSort(vec, pi + 1, r); // after pi;
    }
  }
};

#endif //SORTING_SORTING_H
