//
// Created by Mark Barbaric on 29/10/2019.
//

#ifndef BACKTRACKING_MEDIUMGREEDY_H
#define BACKTRACKING_MEDIUMGREEDY_H

#include <set>
#include <map>
#include <algorithm>

namespace MediumGreedyAlgorithms
{
  
  int maximumWaterUnderVerticalLines(std::vector<int>& vec)
  {
      int l = 0, r = static_cast<int>(vec.size()) - 1;
      auto maxSum = 0;

      while(l < r)
      {
          const auto newMax = (r - l) * std::min(vec[l],vec[r]);
          maxSum = std::max(maxSum, newMax);

          if(vec[l] < vec[r])
              l++;
          else
              r--;
      }

      return maxSum;

  }


  
}

#endif //BACKTRACKING_MEDIUMGREEDY_H
