#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class MinimumPathSum_LeetCode_64 : public IProblem {

  int minpath_recurv(vector<vector<int>>& grid, int r, int c, int rc, int cc)
  {
    if ((r == rc) && (c == cc))
      return grid[r][c];
    if ((r > rc) || (c > cc))
      return INT_MAX;
    cout << "R: " << r << " C:" << c << " cost: " << grid[r][c] << endl;
    return grid[r][c] + min(minpath_recurv(grid, r + 1, c, rc, cc), minpath_recurv(grid, r, c + 1, rc, cc));
  }

  int minpath_dp(vector<vector<int>>& grid, int r, int c, int rc, int cc, vector<vector<int>>& dp)
  {
    if ((r == rc) && (c == cc))
      return grid[r][c];
    if ((r > rc) || (c > cc))
      return INT_MAX;
    if (dp[r][c] != -1)
      return dp[r][c];
    cout << "R: " << r << " C:" << c << " cost: " << grid[r][c] << endl;
    dp[r][c] = grid[r][c] + min(minpath_dp(grid, r + 1, c, rc, cc, dp), minpath_dp(grid, r, c + 1, rc, cc, dp));
    return dp[r][c];
  }
  int minPathSum_Recursive(vector<vector<int>>& grid) {
    int rc = grid.size()-1, cc = grid[0].size()-1;
    return minpath_recurv(grid, 0, 0, rc, cc);
  }

  int minPathSum_DP(vector<vector<int>>& grid) {
    int rc = grid.size() - 1, cc = grid[0].size() - 1;
    vector<vector<int>> dp(grid.size());
    for (size_t i = 0; i < grid.size(); i++)
    {
      dp[i].resize(grid[i].size());
      for (size_t j = 0; j < grid[0].size(); j++)
      {
        dp[i][j] = -1;
      }
    }
    return minpath_dp(grid, 0, 0, rc, cc, dp);
  }

  int minPathSum_Iterative(vector<vector<int>>& grid) {
    int rc = grid.size() - 1, cc = grid[0].size() - 1;
    vector<vector<int>> dp(grid.size());
    for (size_t i = 0; i < grid.size(); i++)
    {
      dp[i].resize(grid[i].size());
    }

    dp[0][0] = grid[0][0];

    for (size_t r = 1; r < grid.size(); r++)
      dp[r][0] = dp[r - 1][0] + grid[r][0];

    for (size_t c = 1; c < grid[0].size(); c++)
      dp[0][c] = dp[0][c - 1] + grid[0][c];

    for(size_t i=1;i< grid.size();i++)
      for (size_t j = 1; j < grid[0].size(); j++)
      {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    return dp[rc][cc];
  }
public:
  int run() override
  {
    cout << "MinimumPathSum_LeetCode_64" << endl;
    //vector<vector<int>> grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
    vector<vector<int>> grid = { {1, 2, 3},{4, 5, 6}};
    cout << "minPathSum Recursive : " << minPathSum_Recursive(grid) << endl;
    cout << endl << endl;
    cout << "minPathSum DP : " << minPathSum_DP(grid) << endl;
    cout << "minPathSum Iterative : " << minPathSum_Iterative(grid) << endl;
    return 0;
  }
};