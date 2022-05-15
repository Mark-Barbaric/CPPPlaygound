#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "include/Header.h"

namespace BSAlgorithms
{
	template <typename T>
	inline int RecursiveBinarySearch(int l, int r, int v, const std::vector<T>& arr)
	{
		if (r >= l)
		{
			const auto m = l + (r - l) / 2;
			
			if (arr[m] == v)
				return m;
			
			if (v > arr[m])
				return RecursiveBinarySearch(m + 1, r, v, arr);
			else
				return RecursiveBinarySearch(l, m - 1, v, arr);
			
		}

		return -1;
	}

	template<typename T>
	inline int IterativeBinarySearch(int v, const std::vector<T>& arr)
	{
		int l = 0, r = arr.size() - 1;

		while(l <= r)
		{
			const auto m = l + (r - l) / 2;

			if (arr[m] == v)
				return m;
			else
			{
				if (arr[m] > v)
					r = m - 1;
				else if (arr[m] < v)
					l = m + 1;
			}
		}

		return -1;
	}

	template <typename T>
	inline int FindPivot(int l, int r, const std::vector<T>& arr)
	{
		if (l == 0 && r == arr.size() - 1 && arr[l] < arr[r])
			return 0;
		
		if(l <= r)
		{
			const auto p = l + (r - l) / 2;

			if (arr[p + 1] < arr[p])
				return p + 1;

			else
			{
				if (arr[p] < arr[l])
					return FindPivot(l, p - 1, arr);
				else
					return FindPivot(p + 1, r, arr);
			}
			
		}

		return 0;
	}

	template <typename T>
	inline int PivotedBinarySearch(int l, int r, int v, const std::vector<T>& arr)
	{
		if (arr[l] < arr[r])
			return RecursiveBinarySearch(0, arr.size() - 1, v, arr);

		const auto p = FindPivot(0, arr.size() - 1, arr);

		if (arr[p] == v)
			return p;

		else
		{
			if (arr[0] < v)
				return RecursiveBinarySearch(l, p, v, arr);
			else
				return RecursiveBinarySearch(p, r, v, arr);
		}

		return -1;
	}
	
}



#endif
