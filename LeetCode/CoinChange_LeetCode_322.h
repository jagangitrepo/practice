#pragma once

#include "common.h"
#include "IProblem.h"

class CoinChange_LeetCode_322 : public IProblem {
  int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> DP;
    DP.resize(amount);
    DP[0] = 1;

    for (isize_tnt i = 1; i <= amount; i++)
    {
      for (size_t j = 0; j < coins.size(); j++)
      {
        if(i<=j)
          DP[i] = min(DP[i], DP[i - coins[j]]);
      }
    }
    return DP[DP.size()-1];
  }
public:
  virtual int run() override
  {
    std::cout << "CoinChange_LeetCode_322" << endl;
    std::vector<int> coins = { 1,2,5 };
    int amount = 11;
    std::cout << "Min coins: " << coinChange(coins, amount) << endl;
    return 0;
  }
};