#include "common.h"

//Coding Platforms
#include "ICodingPlatform.h"
#include "LeetCode/LeetCode.h"
#include "GeeksForGeeks/GeeksForGeeks.h"
#include "StriverSDE/StriverSDE.h"
#

int main()
{
  std::vector<std::unique_ptr<ICodingPlatform>> codingplatforms;
  codingplatforms.emplace_back(std::make_unique<LeetCode>());
  codingplatforms.emplace_back(std::make_unique<GeeksForGeeks>());
  codingplatforms.emplace_back(std::make_unique<StriverSDE>());

  for (auto& codingplatform : codingplatforms)
  {
    std::cout << "Executing Problems from : " << codingplatform->PlatfromName() << std::endl;
    codingplatform->RunAll();
    std::cout << "---------------------------------------------------------------" << std::endl;
  }
  return 0;
}