// GeeksForGeeks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "common.h"
#include "ICodingPlatform.h"
#include "IProblem.h"

// Problems
#include "Array_Subarrays.h"

class GeeksForGeeks : public ICodingPlatform
{
public:
  GeeksForGeeks():ICodingPlatform("LeetCode")
  {
    Register(std::make_unique<Subarry_With_equal_1_0>());
  }
};
