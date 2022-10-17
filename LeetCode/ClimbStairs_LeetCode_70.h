#pragma once

#include "common.h"
#include "IProblem.h"

class ClimbStairs_LeetCode_70 : public IProblem {
  int DeepSrch(int currstep, int laststep, vector<int>& memo)
  {
    //Base case
    if (currstep == laststep)
      return 1;
    if (currstep >= laststep)
      return 0;

    if (memo[currstep] != -1)
      return memo[currstep];
    
    memo[currstep] = DeepSrch(currstep + 1, laststep, memo) + DeepSrch(currstep + 2, laststep, memo);
    return memo[currstep];
  }

  int climbStairs(int n) {
    vector<int> memo(n, -1);
    return DeepSrch(0, n, memo);
  }
public:
  int run() override
  {
    cout << "ClimbStairs_LeetCode_70" << endl;
    int steps = 2;
    cout << "Distinct ways: " << climbStairs(steps)<<endl;
    return 0;
  }
};