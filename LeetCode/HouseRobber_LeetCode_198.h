#pragma  once

#include "common.h"
#include "IProblem.h"

using namespace std;

class HouseRobber_LeetCode_198 : public IProblem {
  int DeepSrch(vector<int>& nums, int curridx, int n, vector<int>& memo)
  {
    if (curridx >= n)
      return 0;
    if (curridx == n)
      return nums[curridx];

    if (memo[curridx] != -1)
      return memo[curridx];

    memo[curridx] = nums[curridx] + max(DeepSrch(nums, curridx + 2, n, memo), DeepSrch(nums, curridx + 3, n, memo));
    return memo[curridx];
  }

  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);
    vector<int> memo(nums.size()+1, -1);
    return max(DeepSrch(nums, 0, nums.size(), memo), DeepSrch(nums, 1, nums.size(), memo));
  }
public:
  int run() override
  {
    cout << "HouseRobber_LeetCode_198" << endl << endl;
    HouseRobber_LeetCode_198 sl;
    //vector<int> nums = { 1,3, 1 }; // 3
    //vector<int> nums = { 2,1,1,2 };
/*    vector<int> nums = { 1,2,3,1 };*/
    ///vector<int> nums = { 2,1,1,2 };
    //vector<int> nums = { 2,7,9,3,1 };
    vector<int> nums = { 114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240 };
    cout << "Maximum Amount: " << rob(nums) << endl;
    return 0;
  }
};