#ifndef DAILY_PROBLEMS_H
#define DAILY_PROBLEMS_H
#include <map>
#include <set>
#include <vector>
#include <algorithm>

namespace DailyProblems
{
	inline bool ArraySum(std::vector<int>& arr, int target)
	{
		std::map<int, int> mapDiff;
		
		for (int i = 0; i < arr.size(); ++i)
		{
			mapDiff[arr[i]] = i;
		}
		
		for(int i = 0; i < arr.size(); ++i)
		{
			const auto diff = target - arr[i];
			const auto res = mapDiff.find(diff);
			const auto index = mapDiff[arr[i]];

			if (mapDiff.find(diff) != mapDiff.end() && mapDiff[diff] != i)
				return true;
		}


		return false;		
	}

	inline bool ArraySumOptimised(std::vector<int>& arr, int target)
	{
		std::set<int> set;

		for(auto& a :arr)
		{
			const auto diff = target - a;

			if (set.find(a) != set.end())
				return true;

			set.insert(diff);
		}

        return false;
	}

	inline int LargestNonAdjacentSum(std::vector<int>& arr)
	{
		int incl = arr[0], excl = 0;

		for(int i = 1; i < arr.size(); ++i)
		{
			const auto exclNew = std::max(incl, excl);
			incl = excl + arr[i];
			excl = exclNew;			
		}

		return std::max(incl, excl);
		
	}

	
	inline int GetStockProfit(std::vector<int>& arr)
	{
		auto minPrice = arr[0];
		auto maxDiff = 0;

		for(int i = 1; i < arr.size(); ++i)
		{
			const auto p = arr[i];

			if (p - minPrice > maxDiff)
				maxDiff = p - minPrice;
			if (p < minPrice)
				minPrice = p;
		}

		return maxDiff;		
	}

	inline int minimumLoss(std::vector<long>& price) {

		auto minLoss = LONG_MIN;

		std::map<long, int> map;
		
		for(int i = 0; i < price.size(); ++i)
		{
			map[price[i]] = i;
		}

		std::sort(price.begin(), price.end());

		for (int i = 1; i < price.size(); ++i)
		{
			const auto p1 = price[i - 1];
			const auto p2 = price[i];
			const auto diff = p1 - p2;
			
			if(diff > minLoss)
			{
				const auto idx1 = map[p1];
				const auto idx2 = map[p2];

				if(idx2 < idx1)
				{
					minLoss = diff;
				}
			}
		}
		
		return -minLoss;
	}
	
}



#endif