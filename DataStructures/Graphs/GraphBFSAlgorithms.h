//
//  GraphBFSAlgorithms.h
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 15/08/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//

#ifndef GraphBFSAlgorithms_h
#define GraphBFSAlgorithms_h

#include "../../Header.h"

namespace GraphBFSAlgorithms
{
  int MinimumDistance(int u, std::vector<std::list<int>>& adjacencyList)
  {
    std::vector<bool> visited(adjacencyList.size(), false);
    std::list<int> queue;
    std::vector<int> dist (adjacencyList.size(), 0);
    
    visited[u] = true;
    queue.push_back(u);
    
    while(!queue.empty())
    {
      auto i = queue.front();
      queue.pop_front();
    
      for(auto it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it)
      {
        if(!visited[*it])
        {
          dist[i] += 1;
          visited[*it] = true;
          queue.push_back(*it);
        }
      }
    }
    
    auto minDist = INT_MAX;
    
    for(auto& d : dist)
    {
      if(d > 0)
        minDist = std::min(minDist, d);
    }
    
    return minDist;
    
  }

}

#endif /* GraphBFSAlgorithms_h */
