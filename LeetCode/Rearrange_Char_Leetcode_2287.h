#pragma once
#include "common.h"
#include "IProblem.h"

using namespace std;

class Rearrange_Char_Leetcode_2287 : public IProblem {
  int rearrangeCharacters(string s, string target) {
    if (s.empty() || target.empty())
      return 0;

    int matchcount = 0, wordcount = 0;
    for(char sourcechar : s)
      for (char targetchar : target)
      {
        cout << "S: " << sourcechar << " T: " << targetchar << endl;;
        if (sourcechar == targetchar)
        {
          //cout << sourcechar << " ";
          matchcount += 1;
        }
        if (matchcount == target.size())
        {
          wordcount += 1;
          matchcount = 0;
          //cout << endl;
        }
      }
    return wordcount;
  }

  int rearrangeCharacters_2(string s, string target) {
    if (s.empty() || target.empty())
      return 0;

    int matchcount = 0, wordcount = 0;
    std::map<char, int> targethashmap, sourcehashmap;

    for (char t : target)
    {
      targethashmap[t] += 1;     
    }

    for (char src : s)
    {
      sourcehashmap[src] += 1;
    }

    char mincharidx;
    int minval = INT_MAX;
    for (auto srcpair : targethashmap)
    {
      if (srcpair.second < minval)
      {
        minval = srcpair.second;
        mincharidx = srcpair.first;
      }
    }

    return sourcehashmap[mincharidx] / targethashmap[mincharidx];
  }
public:
  int run() override
  {
    cout << "Rearrange_Char_Leetcode_2287" << endl;
    string s= "abcba", target = "abc";
    //string s = "ilovecodingonleetcode", target = "code";
    //string s = "abbaccaddaeea", target = "aaaaa";
    //string s = "codecodecodecode", target = "codecode";
    cout << "Match Count: " << rearrangeCharacters_2(s, target) << endl;
    return 0;
  }
};