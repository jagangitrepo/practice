#pragma once

#include "IProblem.h"


class Subarry_With_equal_1_0 : public IProblem
{

  //Function to count subarrays with 1s and 0s.
  long long int countSubarrWithEqualZeroAndOne(vector<int>&nums)
  {
    for (int & num : nums)
    {
      if (num == 0)
        num = -1;
    }
    long long sum = 0, count = 0;
    unordered_map<long long, long long> um;
    for (auto& num : nums)
    {
      sum += num;
      um[sum]++;
      if (sum == 0)
        count += um[sum];
      else
        count += um[sum] - 1;
    }
    return count;
  }
public:
  int run() override
  {
    vector<int> arr = { -2, 0, 3, -5, 2, -1 };
    vector<int> prefixsum;
    prefixsum.resize(arr.size());

    prefixsum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
      prefixsum[i] = arr[i] + prefixsum[i - 1];
    }

    for (auto num : arr)
    {
      cout << num << " ";
    }
    cout << endl;

    for (auto num : prefixsum)
    {
      cout << num << " ";
    }
    cout << endl;

    vector<int> nums = { 1,0,0,1,0,1,1 };
    cout << "Output: " << countSubarrWithEqualZeroAndOne(nums) << endl;
    return 1;
  }
};