//
//  GraphIslandAlgos.h
//  AlgorithmsAndDatastructures
//
//  Created by Mark Barbaric on 15/08/2020.
//  Copyright © 2020 Mark Barbaric. All rights reserved.
//

#ifndef GraphIslandAlgos_h
#define GraphIslandAlgos_h

#include "../../Header.h"

namespace GraphIslandsAlgos
{

bool IsSafe(int r, int c, std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited)
{
  return(r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size() && !visited[r][c] && matrix[r][c]);
}

int dfsUtilMaxArea(int r, int c, std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited)
{
  if(IsSafe(r, c, matrix, visited))
  {
    visited[r][c] = true;
    return (1 + dfsUtilMaxArea(r, c + 1, matrix, visited) + dfsUtilMaxArea(r + 1, c, matrix, visited)
            + dfsUtilMaxArea(r, c - 1, matrix, visited) + dfsUtilMaxArea(r - 1, c, matrix, visited));
  }
  
  return 0;
}

int MaxAreaOfIsland(std::vector<std::vector<int>>& adjacencyMatrix)
{
  auto maxArea = 0;
  
  int r = adjacencyMatrix.size(), c = adjacencyMatrix[0].size();
  std::vector<std::vector<bool>> visited (r, std::vector<bool>(c, false));
  
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      if(!visited[i][j] && adjacencyMatrix[i][j])
      {
        maxArea = std::max(maxArea, dfsUtilMaxArea(i, j, adjacencyMatrix, visited));
      }
    }
  }
  return maxArea;
}

void dfsUtilNumIslands(int r, int c, std::vector<std::vector<int>>& adjacencyMatrix, std::vector<std::vector<bool>>& visited)
{
  if(IsSafe(r, c, adjacencyMatrix, visited))
  {
    visited[r][c] = true;
    dfsUtilNumIslands(r + 1, c, adjacencyMatrix, visited);
    dfsUtilNumIslands(r - 1, c, adjacencyMatrix, visited);
    dfsUtilNumIslands(r, c + 1, adjacencyMatrix, visited);
    dfsUtilNumIslands(r, c - 1, adjacencyMatrix, visited);
  }
}

inline int numIslands(std::vector<std::vector<int>>& adjacencyMatrix)
{
  const auto r = adjacencyMatrix.size();

  if (r == 0)
    return 0;

  const auto c = adjacencyMatrix[0].size();

  std::vector <std::vector<bool>> visited(r, std::vector<bool>(c, false));
  auto numIslands = 0;

  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      if(!visited[i][j] && adjacencyMatrix[i][j])
      {
        dfsUtilNumIslands(i, j, adjacencyMatrix, visited);
        numIslands++;
      }
    }
  }

  return numIslands;
}
}

#endif /* GraphIslandAlgos_h */
