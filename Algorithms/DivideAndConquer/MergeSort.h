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
  //
  //
  long long merge(std::vector<T>& vec, std::vector<T>& temp, int l, int m, int r)
  {
    // populate left and right vectors for swapping

      auto count = 0, i = l, j = m, k = l;

	  while (i <= (m - 1) && j <= r)
	  {
	      if (vec[i] <= vec[j])
	          temp[k++] = vec[i++];
	      else
	      {
	          temp[k++] = vec[j++];
	          count += m - i;
	    }
	}

  	while (i <= (m - 1))
  	{
        temp[k++] = vec[i++];
  	}

  	while (j <= r)
  	{
        temp[k++] = vec[j++];
  	}

  	for(int i = l; i <= r; ++i)
  	{
        vec[i] = temp[i];
  	}
  	
 
    return count;
  }
  
  
public:
  MergeSort() = default;
  
  long long mergeSort(std::vector<T>& vec, int l, int r)
  {
      long long sortCount = 0;
      std::vector<T> temp(vec.size(), 0);

      if (r > l)
      {
          auto mid = l + (r - l) / 2;
          sortCount = mergeSort(vec, l, mid);
          sortCount += mergeSort(vec, mid + 1, r);
          sortCount += merge(vec, temp, l, mid + 1, r);
      }

      return sortCount;
  }


};

#endif //SORTING_MERGESORTCOUNT_H
