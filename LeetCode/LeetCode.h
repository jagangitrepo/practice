#pragma once
#include "ICodingPlatform.h"

//Problems
#include "FloodFill_LeetCode_733.h"
#include "NumberofIslandsLeetCode_200.h"
#include "MaxAreaOfIslandLeetCode_695.h"
#include "NumberOfClosedIslandsLeetCode_1254.h"
#include "CountSubIslandsLeetCode_1905.h"
#include "MaxDistanceLeetCode_1162.h"
#include "HouseRobber_LeetCode_198.h"
#include "Nth_Stairs_DP.h"
#include "FrogJump.h"
#include "ClimbStairs_LeetCode_70.h"
#include "MinCostClimbingStairs_LeetCode_746.h"
#include "HouseRobber_LeetCode_213.h"
#include "JumpGame_LeetCode_55.h"
#include "Rearrange_Char_Leetcode_2287.h"
#include "MinimumPathSum_LeetCode_64.h"
#include "NoofPathMatrix.h"

class LeetCode : public ICodingPlatform
{
public:
  LeetCode():ICodingPlatform("LeetCode") {
    Register(std::make_unique<FloodFill_LeetCode_733>());
    Register((std::make_unique<NumberofIslandsLeetCode_200>()));
    Register((std::make_unique<MaxAreaOfIslandLeetCode_695>()));
    Register((std::make_unique<NumberOfClosedIslandsLeetCode_1254>()));
    Register((std::make_unique<CountSubIslandsLeetCode_1905>()));
    //Register((std::make_unique<MaxDistanceLeetCode_1162>()));
    Register((std::make_unique<HouseRobber_LeetCode_198>()));
    Register((std::make_unique<HouseRobber_LeetCode_213>()));
    Register((std::make_unique<Nth_Stairs_DP>()));
    Register((std::make_unique<Frog_Jump>()));
    Register((std::make_unique<ClimbStairs_LeetCode_70>()));
    Register((std::make_unique<MinCostClimbingStairs_LeetCode_746>()));
    Register((std::make_unique<JumpGame_LeetCode_55>()));
    Register((std::make_unique<Rearrange_Char_Leetcode_2287>()));
    Register((std::make_unique<MinimumPathSum_LeetCode_64>()));
    Register((std::make_unique<NoofPathMatrix>()));
  };
}; 