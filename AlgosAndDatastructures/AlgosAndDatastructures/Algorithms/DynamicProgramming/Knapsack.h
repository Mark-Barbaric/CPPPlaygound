//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H

#include <vector>
#include <iostream>

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
