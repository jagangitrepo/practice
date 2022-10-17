#pragma once

#include "common.h"
#include "IProblem.h"

using namespace std;

class JumpGame_LeetCode_55 : public IProblem {
  bool canJump(vector<int>& nums) {
    int lastidx = nums.size() - 1;
    for (size_t i=0;i< nums.size();)
    {
      if (nums[i] == 0)
        return false;
      if (i == lastidx)
        return true;
      i = i + nums[i];
    }
    return false;
  }
public:
  int run() override
  {
    cout << "JumpGame_LeetCode_55" << endl;
    //vector<int> nums = { 2,3,1,1,4 };
    vector<int> nums = { 3, 2, 1, 0, 4 };
    cout << "Can jump: " << canJump(nums) << endl;
    return 0;
  }
};