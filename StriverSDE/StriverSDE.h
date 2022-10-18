#pragma once
#include "ICodingPlatform.h"

//Problems
#include "DFS.h"
#include "BFS.h"

class StriverSDE : public ICodingPlatform
{
public:
  StriverSDE() :ICodingPlatform("StriverSDE")
  {
    Register(std::make_unique<DFS>());
    Register(std::make_unique<BFS>());
  };
};