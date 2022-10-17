#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class Frog_Jump : public IProblem {
  int frogJump(vector<int>& heights, int currstair, vector<int>& dp)
  {
    if (currstair < 0)
      return 0;
    if (dp[currstair] != -1)
      return dp[currstair];
    dp[currstair] = min(abs(heights[currstair] - frogJump(heights, currstair - 1, dp)), abs(heights[currstair] - frogJump(heights, currstair - 2, dp)));
    return dp[currstair];
  }
public:
  int run() override
  {
    cout << "Frog_Jump" << endl;    
    vector<int> heights = { 10, 20, 30, 10 };
    vector<int> dp(heights.size() + 1, -1);
    cout << "Min cost: " << frogJump(heights, heights.size()-1, dp)<<endl;
    return 0;
  }
};