//
// Created by Mark Barbaric on 27/09/2019.
//

#ifndef SORTING_MERGESORT_H
#define SORTING_MERGESORT_H

template<typename T>
class MergeSort
{
  // Time complexity o(nLogn)
  // Space o(n)
  int merge(std::vector<T>& vec, int l, int m, int r)
  {
    // populate left and right vectors for swapping
    auto i = 0, j = 0, k = l;
    auto count = 0;
    const auto n1 = m - l + 1;
    const auto n2 = r - m;
    
    std::vector<T> leftArr (n1, 0), rightArr(n2, 0);
    
    for(int a = 0; a < n1; ++a)
      leftArr[a] = vec[l + a]; // up to mid point
    
    for(int b = 0; b < n2; ++b)
      rightArr[b] = vec[m + b + 1]; // after mid point
    
    while(i < n1 && j < n2)
    {
      //compare left and right arrays
      if(leftArr[i] <= rightArr[j])
      {
        vec[k++] = leftArr[i++];
      }
      else
      {
        vec[k++] = rightArr[j++];
        count = count + n1 - i;
      }
    }
    
    while(i < n1)
      vec[k++] = leftArr[i++];
    while(j < n2)
      vec[k++] = rightArr[j++];
    
    return count;
  }
  
  
public:
  MergeSort() = default;
  
  int mergeSort(std::vector<T>& vec, int l, int r)
  {
      auto sortCount = 0;

      if (l < r)
      {
          auto mid = l + (r - l) / 2;
          sortCount = mergeSort(vec, l, mid);
          sortCount += mergeSort(vec, mid + 1, r);
          sortCount += merge(vec, l, mid, r);
      }

      return sortCount;
  }

};

#endif //SORTING_MERGESORTCOUNT_H
