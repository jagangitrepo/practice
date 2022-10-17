#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class NumberofIslandsLeetCode_200 : public IProblem {
  bool DFS(vector<vector<char>>& grid, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if (((cr < 0) && (cr > m)) || ((cc < 0) && (cc > n)))
    {
      return false;
    }

    if(visited[cr][cc])
      return ((grid[cr][cc] == '0') ? true : false);

    visited[cr][cc] = true;
    if (grid[cr][cc] == '0')
      return true;

    // iterate over four direction
    // Top
    bool top = false;
    bool left = false;
    bool right = false;
    bool bottom = false;
    if ((cr - 1) >= 0)
    {
      int ccr = cr - 1;
      if (!visited[ccr][cc])
      {
        top = DFS(grid, ccr, cc, m, n, visited);
      }
      else {
        top = ((grid[ccr][cc] == '0') ? true : false);
      }
    }
    //bottom
    if ((cr + 1) < m)
    {
      int ccr = cr + 1;
      if (!visited[ccr][cc])
      {
        bottom = DFS(grid, ccr, cc, m, n, visited);
      }
      else {
        bottom = ((grid[ccr][cc] == '0') ? true : false);
      }
    }
    // left
    if ((cc - 1) >= 0)
    {
      int ccc = cc - 1;
      if (!visited[cr][ccc])
      {
        left = DFS(grid, cr, ccc, m, n, visited);
      }
      else {
        left = ((grid[cr][ccc] == '0') ? true : false);
      }
    }
    // right
    if ((cc + 1) < n)
    {
      int ccc = cc + 1;
      if ((!visited[cr][ccc]))
      {
        right = DFS(grid, cr, ccc, m, n, visited);
      }
      else {
        right = ((grid[cr][ccc] == '0') ? true : false);
      }
    }
    return (top || left || right || bottom);
  }

  int DeepSrch(vector<vector<char>>& grid, int cr, int cc, int m, int n, vector<vector<bool>>& visited)
  {
    if (((cr < 0) && (cr > m)) || ((cc < 0) && (cc > n)))
    {
      return -1;
    }

    if (visited[cr][cc])
      return 0;

    visited[cr][cc] = true;
    if (grid[cr][cc] == '0')
      return 0;

    // iterate over four direction
    // Top
    if ((cr - 1) >= 0)
    {
      int ccr = cr - 1;
      if (!visited[ccr][cc])
      {
        DeepSrch(grid, ccr, cc, m, n, visited);
      }
    }
    //bottom
    if ((cr + 1) < m)
    {
      int ccr = cr + 1;
      if (!visited[ccr][cc])
      {
        DeepSrch(grid, ccr, cc, m, n, visited);
      }
    }
    // left
    if ((cc - 1) >= 0)
    {
      int ccc = cc - 1;
      if (!visited[cr][ccc])
      {
        DeepSrch(grid, cr, ccc, m, n, visited);
      }
    }
    // right
    if ((cc + 1) < n)
    {
      int ccc = cc + 1;
      if ((!visited[cr][ccc]))
      {
        DeepSrch(grid, cr, ccc, m, n, visited);
      }
    }
    return 1;
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    int islandcnt = 0;
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
       if (grid[r][c] == '1') {
         if (DeepSrch(grid, r, c, m, n, visited) == 1)
         {
           islandcnt += 1;
         }
       }
     }
    return islandcnt;
  }
  int run() override {
    cout << "NumberofIslandsLeetCode_200" << endl << endl;
    NumberofIslandsLeetCode_200 sl;
    vector<vector<char>> grid;

//     grid.push_back({ '1','1','1','1','0' });
//     grid.push_back({ '1','1','0','1','0' });
//     grid.push_back({ '1','1','0','0','0' });
//     grid.push_back({ '0','0','0','0','0' });

//     grid.push_back({ '1','1','0','0','0' });
//     grid.push_back({ '1','1','0','0','0' });
//     grid.push_back({ '0','0','1','0','0' });
//     grid.push_back({ '0','0','0','1','1' });

    grid.push_back({ '1' , '1' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '1' });
    grid.push_back({ '1' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '1' });
    grid.push_back({ '1' });
    grid.push_back({ '0' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '0' });
    grid.push_back({ '0' });
    grid.push_back({ '0' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '1' , '1', '1'});
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '0' , '0', '0' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '1' , '0', '1', '0' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '0' , '1', '0', '1' , '1', '1' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '0' , '1', '0', '1' , '0', '1' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '0' });
    cout << "numIslands: " << numIslands(grid) << endl;

    grid.clear();
    grid.push_back({ '1' });
    cout << "numIslands: " << numIslands(grid) << endl;
    return 0;
  }
};