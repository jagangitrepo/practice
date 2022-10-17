// 
//
#include <iostream>
#include <vector>
#include "IProblem.h"

using namespace std;

class FloodFill_LeetCode_733 : public IProblem{
  void DFS(vector<vector<int>>& image, int sr, int sc, int existingColor, int newColor, int m, int n, vector<vector<bool>>& visited)
  {
    if (((sc < 0) && (sc > n)) || ((sr < 0) && (sr > m)))
    {
      return;
    }

    visited[sr][sc] = true;
    image[sr][sc] = newColor;

    // iterate over four direction
    // Top
    if ((sc + 1) < n)
    {
      int nsc = (sc + 1);
      if ((image[sr][nsc] == existingColor) && (!visited[sr][nsc]))
      {
      /*  visited[sr][nsc] = true;*/
        image[sr][nsc] = newColor;
        DFS(image, sr, nsc, existingColor, newColor, m, n, visited);
      }
    }
    //bottom
    if ((sc - 1) >= 0)
    {
      int nsc = sc - 1;
      if ((image[sr][nsc] == existingColor) && (!visited[sr][nsc]))
      {
        /*visited[sr][nsc] = true;*/
        image[sr][nsc] = newColor;
        DFS(image, sr, nsc, existingColor, newColor, m, n, visited);
      }
    }
    // left
    if ((sr - 1) >= 0)
    {
      int nsr = sr - 1;
      if ((image[nsr][sc] == existingColor) && (!visited[nsr][sc]))
      {
       /* visited[nsr][sc] = true;*/
        image[nsr][sc] = newColor;
        DFS(image, nsr, sc, existingColor, newColor, m, n, visited);
      }
    }
    // right
    if ((sr + 1) < m)
    {
      int nsr = sr + 1;
      if ((image[nsr][sc] == existingColor) && (!visited[nsr][sc]))
      {
        /*visited[nsr][sc] = true;*/
        image[nsr][sc] = newColor;
        DFS(image, nsr, sc, existingColor, newColor, m, n, visited);
      }
    }
    return;
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<bool>> visited;
    visited.resize(image.size());
    for (size_t r = 0; r < image.size(); r++)
    {
      visited[r].resize(image[r].size());
      for (size_t c = 0; c < image[r].size(); c++)
      {
        visited[r][c] = false;
      }
    }
    DFS(image, sr, sc, image[sr][sc], newColor, image.size(), image[0].size(), visited);
    return image;
  }
public:
  int run() override
  {
    cout << "FloodFill_LeetCode_733" << endl << endl;
    FloodFill_LeetCode_733 sl;
    vector<vector<int>> image;
    //[[1,1,1],[1,1,0],[1,0,1]]
    /*image.push_back({ 1,1,1 });
    image.push_back({ 1,1,0 });
    image.push_back({ 1,0,1 });
    sl.floodFill(image, 1, 1, 2);*/

    image.push_back({ 0,0,0 });
    image.push_back({ 0,1,0 });

    sl.floodFill(image, 0, 0, 1);
    for (auto row : image)
    {
      for (auto pixel : row)
      {
        cout << pixel << " ";
      }
      cout << endl;
    }
    return 0;
  }
};