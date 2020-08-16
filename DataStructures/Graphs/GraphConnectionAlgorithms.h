//
//  GraphConnectionAlgorithms.h
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 15/08/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//

#ifndef GraphConnectionAlgorithms_h
#define GraphConnectionAlgorithms_h

#include "../../Header.h"

namespace GraphConnectionAlgorithms
{

  void dfsUtilNumConnectedComponents(int u, std::vector<std::list<int>>& adjacencyList, std::vector<bool>& visited)
  {
    visited[u] = true;
    
    for(auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it)
    {
      const int i = *it;
      if(!visited[i])
        dfsUtilNumConnectedComponents(i, adjacencyList, visited);
    }
  }

  int NumConnectedComponents(std::vector<std::list<int>>& adjacencyList)
  {
    std::vector<bool> visited(adjacencyList.size(), false);
    auto count = 0;
    
    for(int i = 0; i < adjacencyList.size(); ++i)
    {
      if(!visited[i])
      {
        dfsUtilNumConnectedComponents(i, adjacencyList, visited);
        count ++;
      }
      
    }
    return count;
  }

int dfsUtilMergeIntervals(int s, std::vector<std::list<int>>& adjacencyList, std::vector<bool>& visited)
{
  visited[s] = true;
  
  for(auto it = adjacencyList[s].begin(); it != adjacencyList[s].end(); ++it)
  {
    const int i = *it;
    if(!visited[i])
    {
      return dfsUtilMergeIntervals(i, adjacencyList, visited);
    }
  }
  
  return s;
}

std::vector<std::vector<int>> MergeIntervals(std::vector<std::list<int>>& adjacencyList)
{
  std::vector<bool> visited(adjacencyList.size(), false);
  std::vector<std::vector<int>> ans;
  
  for(int i = 0; i < adjacencyList.size(); ++i)
  {
    if(!visited[i])
    {
      ans.push_back({i, dfsUtilMergeIntervals(i, adjacencyList, visited)});
    }
  }
  
  return ans;
}

}


#endif /* GraphConnectionAlgorithms_h */
