#pragma once

#include "common.h"
#include "IProblem.h"

using namespace std;

class MaxDistanceLeetCode_1162 : public IProblem {
  int DeepSrch(vector<vector<int>>& grid,int sr, int sc, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if ((cr < 0) || (cr >= m) || (cc < 0) || (cc >= n))
      return 0;

    if (visited[cr][cc])
      return 0;

//      if (grid[cr][cc] == 1)
//        return 1;

    return std::max({ std::abs(sr - cr) + std::abs(sc - cc),
      DeepSrch(grid, sr, sc, cr, cc + 1, m,n, visited),
      DeepSrch(grid, sr, sc, cr, cc - 1, m,n, visited),
      DeepSrch(grid, sr, sc, cr - 1, cc, m,n, visited),
      DeepSrch(grid, sr, sc, cr + 1, cc, m,n, visited),
      DeepSrch(grid, sr, sc, cr - 1, cc - 1, m,n, visited),
      DeepSrch(grid, sr, sc, cr + 1, cc - 1, m,n, visited),
      DeepSrch(grid, sr, sc, cr - 1, cc + 1, m,n, visited),
      DeepSrch(grid, sr, sc, cr + 1, cc + 1, m,n, visited)
      }, [](int a, int b) {
        return a < b;
      });
  }
public:
  int maxDistance(vector<vector<int>>& grid) {
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
    int maxDistance = INT_MIN;
    for (int r = 0; r < m; r++)
      for (int c = 0; c < n; c++)
      {
        if (grid[r][c] == 1)
        {
          int computedmaxDistance = DeepSrch(grid, r, c, r, c, m, n, visited);
          if (computedmaxDistance > maxDistance)
            maxDistance = computedmaxDistance;
        }
      }
    return maxDistance;
  }
  int run() override {
    cout << "MaxDistanceLeetCode_1162" << endl << endl;
    MaxDistanceLeetCode_1162 sl;
    vector<vector<int>> grid;

    grid.push_back({ 1,0,1 });
    grid.push_back({ 0,0,0 });
    grid.push_back({ 1,0,1 });
    cout << "Max Distance: " << maxDistance(grid) << endl;
    return 0;
  }
};