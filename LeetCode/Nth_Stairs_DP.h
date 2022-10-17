#pragma once

#include "common.h"
#include "IProblem.h"

using namespace std;

class Nth_Stairs_DP : public IProblem {
  int Nth_Stairs_recur(int currstair, int n, vector<int>& dp)
  {
    if (currstair == n)
      return 1;
    if (currstair > n)
      return 0;
    if (dp[currstair] != -1)
      return dp[currstair];
    return Nth_Stairs_recur(currstair + 1, n, dp) + Nth_Stairs_recur(currstair + 2, n, dp);
  }

  int Nth_Stairs_iter(int noofstairs)
  {
    if (noofstairs < 3)
      return noofstairs;
    int prev1 = 1, prev2 = 2, noofways = 0;
    for (int i = 2; i < noofstairs; i++)
    {
      noofways = (prev2 + prev1);
      prev1 = prev2;
      prev2 = noofways;
    }
/*    Sleep(10);*/
    return noofways;
  }
public:
  int run() override
  {
    cout << "Nth_Stairs_DP" << endl;
    int noofstairs = 30;
    vector<int> dp(noofstairs + 1, -1);

    auto start = std::chrono::high_resolution_clock::now();
    cout << "Nth_Stairs_recur: " << Nth_Stairs_recur(0, noofstairs, dp) << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto int_usec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Nth_Stairs_recur take usec " << int_usec.count() << endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    cout << "Nth_Stairs_iter: " << Nth_Stairs_iter(noofstairs) << endl;
    auto end1 = std::chrono::high_resolution_clock::now();
    auto int_usec1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    cout << "Nth_Stairs_iter take usec " << int_usec1.count() << endl;
    return 0;
  }
};