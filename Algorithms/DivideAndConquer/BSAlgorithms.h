#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

namespace BS_Algorithms
{
	template <typename T>
	int binarySearch(int l, int r, int v, const std::vector<T>& arr)
	{
		if (r >= l)
		{
			const auto m = l + (r - l) / 2;
			
			if (arr[m] == v)
				return m;
			
			if (v > arr[m])
				return binarySearch(m + 1, r, v, arr);
			else
				return binarySearch(l, m - 1, v, arr);
			
		}

		return -1;
	}

	template <typename T>
	int pivotedBinarySearch(int l, int r, int v, std::vector<T>& vec)
	{
		
	}
	
}



#endif
