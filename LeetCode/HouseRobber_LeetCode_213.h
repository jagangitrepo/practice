#include "common.h"
#include "IProblem.h"

using namespace std;

class HouseRobber_LeetCode_213 : public IProblem {
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
    if (nums.size() == 3)
      return max(max(nums[0], nums[1]), nums[2]);

    vector<int> memo(nums.size() + 1, -1);
    return max(DeepSrch(nums, 0, nums.size()-3, memo), DeepSrch(nums, 1, nums.size(), memo));
  }
public:
  int run() override
  {
    cout << "HouseRobber_LeetCode_213" << endl << endl;
    HouseRobber_LeetCode_213 sl;
    
    //vector<int> nums = { 1,2,3,1}; // 4
    vector<int> nums = { 2,3,2 }; //3
    //vector<int> nums = { 1,2,3 }; //3
    cout << "Maximum Amount: " << rob(nums) << endl;
    return 0;
  }
};