#pragma once
#include <utility>

#include "IProblem.h"

class ICodingPlatform
{
  // Contains all the coding platform specific problems list.
  std::vector<std::unique_ptr<IProblem>> problems;
  std::string platform_name;

public:
  ICodingPlatform(std::string name) : platform_name(std::move(name))
  {
  }

  template<typename T>
  void Register(T &&problem)
  {
    problems.emplace_back(std::forward<T>(problem));
  }

  void RunAll()
  {
    // Run all the registered problems sequentially
    for (auto &problem : problems)
    {
      problem->run();
    }
  }

  std::string PlatfromName()
  {
    return platform_name;
  };
};
