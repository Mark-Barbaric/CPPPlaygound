#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "include/Header.h"

namespace SortingAlgorithms
{
	void Merge(int l, int m, int r, std::vector<int>& nums)
	{
		// populate left and right vectors for swapping

		std::vector<int> left(m - l + 1, -2), right(r - m, -1);

		for (int i = 0, j = l; i < left.size(); ++i, ++j)
			left[i] = nums[j];

		for (int j = m + 1, i = 0; i < right.size(); ++i, ++j)
			right[i] = nums[j];
		
		auto i = 0, j = 0, k = l;

		while(i < left.size() && j < right.size())
		{
			if (left[i] < right[j])
				nums[k++] = left[i++];
			else
				nums[k++] = right[j++];

		}

		while (i < left.size())
			nums[k++] = left[i++];

		while (j < right.size())
			nums[k++] = right[j++];		
	}


	void MergeSort(int l, int r, std::vector<int>& nums)
	{
		if (l < r)
		{
			auto m = l + (r - l) / 2;
			MergeSort(l, m, nums);
			MergeSort(m + 1, r, nums);
			Merge(l, m, r, nums);
		}
	}
	
}





#endif
