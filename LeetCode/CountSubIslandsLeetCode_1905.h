#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class CountSubIslandsLeetCode_1905 : public IProblem {

  void DeepSrch(vector<vector<int>>& grid, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if ((cr < 0) || (cr >= m) || (cc < 0) || (cc >= n))
      return;

    if (visited[cr][cc])
      return;

    visited[cr][cc] = true;
    if (grid[cr][cc] == 0)
      return;
    DeepSrch(grid, cr - 1, cc, m, n, visited);
    DeepSrch(grid, cr + 1, cc, m, n, visited);
    DeepSrch(grid, cr, cc - 1, m, n, visited);
    DeepSrch(grid, cr, cc + 1, m, n, visited);
    return;
  }

  void floodFill(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if ((cr < 0) || (cr >= m) || (cc < 0) || (cc >= n))
      return;

    if (visited[cr][cc])
      return;

    visited[cr][cc] = true;
    if (grid2[cr][cc] == 0)
      return;

    grid2[cr][cc] = 0;

    floodFill(grid1, grid2, cr - 1, cc, m, n, visited);
    floodFill(grid1, grid2, cr + 1, cc, m, n, visited);
    floodFill(grid1, grid2, cr, cc - 1, m, n, visited);
    floodFill(grid1, grid2, cr, cc + 1, m, n, visited);
    return;
  }
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    if (grid1.empty() || grid2.empty() || (grid1.size() != grid2.size()) || (grid1[0].size() != grid2[0].size()))
      return 0;

    int rc = grid1.size(), cc = grid1[0].size(), noofsublslands = 0;
    vector<vector<bool>> visited;
    visited.resize(grid2.size());
    for (size_t r = 0; r < grid2.size(); r++)
    {
      visited[r].resize(grid2[r].size());
      for (size_t c = 0; c < grid2[r].size(); c++)
      {
        visited[r][c] = false;
      }
    }

    for (auto row : grid2)
    {
      for (auto elem : row)
      {
        cout << elem << " ";
      }
      cout << endl;
    }
    cout << "FloodFill" << endl;
    for (int r = 0; r < rc; r++)
      for (int c = 0; c < cc; c++)
      {
        if ((grid1[r][c] != grid2[r][c]) && (grid2[r][c] == 1))
        {
          floodFill(grid1, grid2, r, c, rc, cc, visited);
        }
      }
    for (auto row : grid2)
    {
      for (auto elem : row)
      {
        cout << elem << " ";
      }
      cout << endl;
    }

    for (int r = 0; r < rc; r++)
      for (int c = 0; c < cc; c++)
      {
        if ((grid2[r][c] == 1) && (!visited[r][c]))
        {
          DeepSrch(grid2, r, c, rc, cc, visited);
          cout << r << "," << c << endl;
          noofsublslands += 1;
        }
      }
    return noofsublslands;
  }
  int run() override {
    cout << "CountSubIslandsLeetCode_1905" << endl << endl;
    CountSubIslandsLeetCode_1905 sl;
    vector<vector<int>> grid1;
    vector<vector<int>> grid2;

//     grid1.push_back({ 1, 1, 1, 0, 0 });
//     grid1.push_back({ 0, 1, 1, 1, 1 });
//     grid1.push_back({ 0, 0, 0, 0, 0 });
//     grid1.push_back({ 1, 0, 0, 0, 0 });
//     grid1.push_back({ 1, 1, 0, 1, 1 });
// 
//     grid2.push_back({ 1, 1, 1, 0, 0 });
//     grid2.push_back({ 0, 0, 1, 1, 1 });
//     grid2.push_back({ 0, 1, 0, 0, 0 });
//     grid2.push_back({ 1, 0, 1, 1, 0 });
//     grid2.push_back({ 0, 1, 0, 1, 0 });

    grid1.push_back({ 1, 0, 1, 0, 1 });
    grid1.push_back({ 1, 1, 1, 1, 1 });
    grid1.push_back({ 0, 0, 0, 0, 0 });
    grid1.push_back({ 1, 1, 1, 1, 1 });
    grid1.push_back({ 1, 0, 1, 0, 1 });
      
    grid2.push_back({ 0, 0, 0, 0, 0 });
    grid2.push_back({ 1, 1, 1, 1, 1 });
    grid2.push_back({ 0, 1, 0, 1, 0 });
    grid2.push_back({ 0, 1, 0, 1, 0 });
    grid2.push_back({ 1, 0, 0, 0, 1 });
    cout << "numIslands: " << countSubIslands(grid1, grid2) << endl;
    return 0;
  }
};