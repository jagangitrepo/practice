-- premake5.lua
workspace "practice"
   configurations { "Debug", "Release" }

project "Practice"
   kind "ConsoleApp"
   language "C++"
   cppdialect 'c++14'
   targetdir "bin/%{cfg.buildcfg}"

   files { 
      "main.cpp",
      "LeetCode/**.*", 
      "GeeksForGeeks/**.*", 
      "StriverSDE/**.*", 
      "include/**.h"
   }

   includedirs {
    'include',
    'LeetCode',
    'StriverSDE/**'
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"