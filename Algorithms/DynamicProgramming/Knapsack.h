//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H

#include <vector>
#include <iostream>

namespace knapsack
{
	struct Item
	{
		int value;
		int weight;
	};

	
	inline int maximumValue(const int capacity, const std::vector<Item> items)
	{
		std::vector<std::vector<int>> knapsackMatrix(capacity + 1, std::vector<int>(items.size(), 0));
		
		for(int i = 0; i < items.size(); ++i)
		{
			for (int j = 1; j <= capacity; ++j)
			{

				const auto excess = capacity - items[j].weight;
			}
			
		}

		return 0;
		
	}
}

class Knapsack {
    int numOfItems;
    int capacityOfItems;
    std::vector<std::vector<int>> knapsackTable;
    int totalBenefit {0};
    std::vector<int> weights;
    std::vector<int> values;

public:
    Knapsack(int numOfItems, int capacity, const std::vector<int>& weights, const std::vector<int>& values);

    void operator()();
    void showResult();

};


#endif //DYNAMIC_PROGRAMMING_KNAPSACK_H
