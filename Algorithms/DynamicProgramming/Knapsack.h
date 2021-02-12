//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H

#include <vector>
#include <algorithm>

namespace knapsack
{

	struct Item
	{
		int value;
		int weight;
	};

	//Complexity O(ic), Space 0(ic)

	
	inline int maximumValue(const int capacity, const std::vector<Item> items)
	{
		std::vector<std::vector<int>> knapsackMatrix(items.size(), std::vector<int>(capacity + 1, 0));
		
		for(int i = 0; i < items.size(); ++i)
		{
			for (int w = 1; w <= capacity; ++w)
			{
				const auto notTakingThis = i > 0 ? knapsackMatrix[i - 1][w] : 0;
				const auto takingThis = items[i].weight <= w ? (items[i].value + knapsackMatrix[i][w - items[i].weight]) : 0;
				knapsackMatrix[i][w] = std::max(notTakingThis, takingThis);
			}
			
		}

		return knapsackMatrix.back().back();
		
	}
}


#endif //DYNAMIC_PROGRAMMING_KNAPSACK_H
