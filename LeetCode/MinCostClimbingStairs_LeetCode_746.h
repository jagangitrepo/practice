#pragma once

#include "common.h"
#include "IProblem.h"

using namespace std;

class MinCostClimbingStairs_LeetCode_746 : public IProblem {
  int DeepSrch(vector<int>& cost, int currstep, int laststep, vector<int>& memo)
  {
    //Base case
    if (currstep == laststep)
      return cost[currstep];
    if (currstep >= laststep)
      return 0;

    if (memo[currstep] != -1)
      return memo[currstep];

    memo[currstep] = cost[currstep] + min(DeepSrch(cost, currstep + 1, laststep, memo), DeepSrch(cost, currstep + 2, laststep, memo));
    return memo[currstep];
  }

  int TopDown(vector<int>& cost)
  {
    vector<int> DP;
    DP.resize(cost.size()+1);
    DP[0] = cost[0];
    DP[1] = cost[1];
    for (size_t i = 2; i <= cost.size(); i++)
    {
      DP[i] = min(DP[i - 1], DP[i - 2]) + ((i == cost.size()) ? 0 : cost[i]);
    }
    return DP[cost.size()];
  }

  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> memo(cost.size() + 1, -1);
    //return min(DeepSrch(cost, 0, cost.size()-1, memo), DeepSrch(cost, 1, cost.size() - 1, memo));
    return TopDown(cost);
  }
public:
  int run() override
  {
    cout << "MinCostClimbingStairs_LeetCode_746" << endl;
    //vector<int> cost = { 10,15,20 };
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    cout << "Min cost: " << minCostClimbingStairs(cost) << endl;
    return 0;
  }
};