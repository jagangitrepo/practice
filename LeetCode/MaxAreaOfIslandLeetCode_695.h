#pragma once

#include "common.h"
#include "IProblem.h"

using namespace std;

class MaxAreaOfIslandLeetCode_695 : public IProblem {
  int DeepSrch(vector<vector<int>>& grid, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if (((cr < 0) && (cr > m)) || ((cc < 0) && (cc > n)))
    {
      return 0;
    }

    if (visited[cr][cc])
      return 0;

    visited[cr][cc] = true;
    if (grid[cr][cc] == 0)
      return 0;

    // iterate over four direction
    // Top
    int left = 0, right = 0, top = 0, bottom = 0;
    if ((cr - 1) >= 0)
    {
      int ccr = cr - 1;
      if (!visited[ccr][cc])
      {
        top = DeepSrch(grid, ccr, cc, m, n, visited);
      }
    }
    //bottom
    if ((cr + 1) < m)
    {
      int ccr = cr + 1;
      if (!visited[ccr][cc])
      {
        bottom = DeepSrch(grid, ccr, cc, m, n, visited);
      }
    }
    // left
    if ((cc - 1) >= 0)
    {
      int ccc = cc - 1;
      if (!visited[cr][ccc])
      {
        left = DeepSrch(grid, cr, ccc, m, n, visited);
      }
    }
    // right
    if ((cc + 1) < n)
    {
      int ccc = cc + 1;
      if ((!visited[cr][ccc]))
      {
        right = DeepSrch(grid, cr, ccc, m, n, visited);
      }
    }
    return 1 + left + right + top + bottom;
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = INT_MIN;
    vector<vector<bool>> visited;
    visited.resize(grid.size());
    for (size_t r = 0; r < grid.size(); r++)
    {
      visited[r].resize(grid[r].size());
      for (size_t c = 0; c < grid[r].size(); c++)
      {
        visited[r][c] = false;
      }
    }

   int m = grid.size(), n = grid[0].size();

   for (int r = 0; r < m; r++)
     for (int c = 0; c < n; c++) {
       if (grid[r][c] == 1) {
         int currMaxArea = DeepSrch(grid, r, c, m, n, visited);
         if (currMaxArea > maxArea)
         {
           maxArea = currMaxArea;
         }
       }
     }

   if (maxArea == INT_MIN)
     return 0;
    return maxArea;
  }
  int run() override {
    cout << "MaxAreaOfIslandLeetCode_695" << endl << endl;
    MaxAreaOfIslandLeetCode_695 sl;
    vector<vector<int>> grid;

//     grid.push_back({ 1,1,1,1,0 });
//     grid.push_back({ 1,1,0,1,0 });
//     grid.push_back({ 1,1,0,0,0 });
//     grid.push_back({ 0,0,0,0,0 });

//     grid.push_back({ 1,1,0,0,0 });
//     grid.push_back({ 1,1,0,0,0 });
//     grid.push_back({ 0,0,1,0,0 });
//     grid.push_back({ 0,0,0,1,1 });

    grid.push_back({ 1 , 1 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 1 });
    grid.push_back({ 1 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 1 });
    grid.push_back({ 1 });
    grid.push_back({ 0 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 0 });
    grid.push_back({ 0 });
    grid.push_back({ 0 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 1 , 1, 1});
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 0 , 0, 0 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 1 , 0, 1, 0 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 0 , 1, 0, 1 , 1, 1 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 0 , 1, 0, 1 , 0, 1 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 0 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;

    grid.clear();
    grid.push_back({ 1 });
    cout << "numIslands: " << maxAreaOfIsland(grid) << endl;
    return 0;
  }
};