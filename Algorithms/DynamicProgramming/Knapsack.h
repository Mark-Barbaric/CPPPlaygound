//
// Created by Mark Barbaric on 24/09/2019.
//

#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H

#include <vector>
#include <iostream>

struct Item
{
    int value;
    int weight;
};

class Knapsack
{
  std::unique_ptr<std::vector<std::vector<int>>> itemsMatrix;
  const int numItems;
  const int maxCapacity;
  
public:
  Knapsack(const int numItems_,
           const int maxCapacity_)
  :numItems(numItems_),
  maxCapacity(maxCapacity_)
  {
    itemsMatrix.reset(new std::vector<std::vector<int>>(numItems, std::vector<int>(maxCapacity + 1, -1)));
  }
  
  int optimumSubjectToItemAndCapacity(const std::vector<Item>& items, int k, int capacity)
  {
    if(k < 0)
      return 0;
    
    if((*itemsMatrix)[k][capacity] == -1) // hasn't been updated yet
    {
      const auto withoutCurrent = optimumSubjectToItemAndCapacity(items, k - 1, capacity);
      const auto withCurrent = capacity < items[k].weight /* item is too large to fit */ ? 0 : items[k].value + optimumSubjectToItemAndCapacity(items, k - 1, capacity - items[k].weight);
      (*itemsMatrix)[k][capacity] = std::max(withCurrent, withoutCurrent);
    }
    
    return (*itemsMatrix)[k][capacity];
  }
  
  int optimumCapacity(const std::vector<Item>& items, int k, int capacity)
  {
    return optimumSubjectToItemAndCapacity(items, static_cast<int>(items.size() - 1), capacity);
  }
  
};

#endif //DYNAMIC_PROGRAMMING_KNAPSACK_H
