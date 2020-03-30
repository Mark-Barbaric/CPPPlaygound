//
// Created by Mark Barbaric on 24/09/2019.
//

#include "Knapsack.h"

#include <algorithm>

Knapsack::Knapsack(int numOfItems_, int capacity_, const std::vector<int>& weights_, const std::vector<int>& values_)
:numOfItems(numOfItems_),
 capacityOfItems(capacity_),
 weights(weights_),
 values(values_)
{
    knapsackTable.resize(numOfItems + 1);

    for(auto& item: knapsackTable)
        item.resize(capacityOfItems + 1);

}

void Knapsack::operator()()
{
    for(int i = 1; i < numOfItems + 1; ++i)
    {
        for(int w = 1; w < capacityOfItems; ++w)
        {
            int notTakingItem = knapsackTable[i - 1][w];
            int takingItem = 0;

            if(weights[i] < w)
            {
                takingItem = values[i] + knapsackTable[i - 1][w - weights[i]];
            }

            knapsackTable[i][w] = std::max(notTakingItem, takingItem);
        }
    }

    totalBenefit = knapsackTable[numOfItems][capacityOfItems];

}

void Knapsack::showResult()
{
    std::cout << "Total Benefit: " << totalBenefit << "\n";

    for(int n = numOfItems, w = capacityOfItems; n > 0; --n)
    {
        if(knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n-1][w])
        {
            std::cout << "We take item: # " << n << "\n";
            w = w - weights[n];
        }
    }
}
