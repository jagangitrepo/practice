#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class NumberOfClosedIslandsLeetCode_1254 : public IProblem {
  void DeepSrch(vector<vector<int>>& grid, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if ((cr < 0) || (cr >= m) || (cc < 0) || (cc >= n))
    {
      return;
    }
    if (visited[cr][cc])
      return;

    visited[cr][cc] = true;
    if (grid[cr][cc] == 1)
      return;

    // iterate over four direction
    DeepSrch(grid, cr - 1, cc, m, n, visited);
    DeepSrch(grid, cr + 1, cc, m, n, visited);
    DeepSrch(grid, cr, cc - 1, m, n, visited);
    DeepSrch(grid, cr, cc + 1, m, n, visited);    
    return ;
  }
public:
  void floodFill(vector<vector<int>>& grid, int sr, int sc, int m, int n, vector<vector<bool>>& visited)
  {
    if ((sc < 0) || (sc >= n) || (sr < 0) || (sr >= m))
    {
      return;
    }

    if (visited[sr][sc])
      return ;

    if (grid[sr][sc] == 0)
    {
      grid[sr][sc] = 1;
    }
    else
      return;

    floodFill(grid, sr - 1, sc, m, n, visited);
    floodFill(grid, sr + 1, sc, m, n, visited);
    floodFill(grid, sr, sc - 1, m, n, visited);
    floodFill(grid, sr, sc + 1, m, n, visited);
    return;
  }

  int closedIsland(vector<vector<int>>& grid) {
    int noofClosedIslands = 0;
   int m = grid.size(), n = grid[0].size();

   // minimum 3x3 matrix required
   if ((m < 3) && (n < 3))
   {
     return 0;
   }

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

   for (int r = 0; r < m; r++)
   {
     if(grid[r][0] == 0){
      floodFill(grid, r, 0, m, n, visited);
     }
   }

   for (int r = 0; r < m; r++)
   {
     if (grid[r][n - 1] == 0) {
       floodFill(grid, r, n - 1, m, n, visited);
     }
   }

   for (int c = 0; c < n; c++)
   {
     if (grid[0][c] == 0) {
       floodFill(grid, 0, c, m, n, visited);
     }
   }

   for (int c = 0; c < n; c++)
   {
     if (grid[m - 1][c] == 0) {
       floodFill(grid, m - 1, c, m, n, visited);
     }
   }

   for (auto row : grid)
   {
     for (auto elem : row)
     {
       cout << elem << " ";
     }
     cout << endl;
   }

   visited.clear();
   visited.resize(grid.size());
   for (size_t r = 0; r < grid.size(); r++)
   {
     visited[r].resize(grid[r].size());
     for (size_t c = 0; c < grid[r].size(); c++)
     {
       visited[r][c] = false;
     }
   }
   for (int r = 0; r < m; r++)
     for (int c = 0; c < n; c++) {
       if ((grid[r][c] == 0) && (!visited[r][c])) {
         DeepSrch(grid, r, c, m, n, visited);
         cout << r << "," << c << endl;
         noofClosedIslands += 1;
       }
     }
    return noofClosedIslands;
  }
  int run() override {
    cout << "NumberOfClosedIslandsLeetCode_1254" << endl << endl;
    NumberOfClosedIslandsLeetCode_1254 sl;
    vector<vector<int>> grid;

//     grid.push_back({ 1,1,1,1,1,1,1 });
//     grid.push_back({ 1,0,0,0,0,0,1 });
//     grid.push_back({ 1,0,1,1,1,0,1 });
//     grid.push_back({ 1,0,1,0,1,0,1 });
//     grid.push_back({ 1,0,1,1,1,0,1 });
//     grid.push_back({ 1,0,0,0,0,0,1 });
//     grid.push_back({ 1,1,1,1,1,1,1 });

//     grid.push_back({ 0,0,1,0,0 });
//     grid.push_back({ 0,1,0,1,0 });
//     grid.push_back({ 0,1,1,1,0 });
// 
//     grid.push_back({ 0, 0, 1, 1, 0, 1, 0, 0, 1, 0 });
//     grid.push_back({ 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 });
//     grid.push_back({ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 });
//     grid.push_back({ 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 });
//     grid.push_back({ 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 });
//     grid.push_back({ 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 });
//     grid.push_back({ 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 });
//     grid.push_back({ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 });
//     grid.push_back({ 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 });
//     grid.push_back({ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 });

    // 4
    grid.push_back({ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 });
    grid.push_back({ 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 });
    grid.push_back({ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 });
    grid.push_back({ 1, 1, 1, 1, 1, 0, 0, 1, 0, 0 });
    grid.push_back({ 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 });
    grid.push_back({ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 });
    grid.push_back({ 1, 0, 1, 0, 0, 0, 0, 1, 1, 0 });
    grid.push_back({ 1, 1, 0, 0, 1, 1, 0, 0, 0, 0 });
    grid.push_back({ 0, 0, 0, 1, 1, 0, 1, 1, 1, 0 });
    grid.push_back({ 1, 1, 0, 1, 0, 1, 0, 0, 1, 0 });

    //6
//     grid.push_back({ 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1 });
//     grid.push_back({ 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 });
//     grid.push_back({ 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 });
//     grid.push_back({ 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0 });
//     grid.push_back({ 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1 });
//     grid.push_back({ 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1 });
//     grid.push_back({ 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 });
//     grid.push_back({ 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 });
//     grid.push_back({ 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0 });
//     grid.push_back({ 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 });
//     grid.push_back({ 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0 });
//     grid.push_back({ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 });
//     grid.push_back({ 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 });
//     grid.push_back({ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1 });

    cout << "numIslands: " << closedIsland(grid) << endl;
    return 0;
  }
};