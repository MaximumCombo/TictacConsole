-- premake5.lua
workspace "TicTacConsole"
   configurations { "Debug", "Release" }

project "TicTacConsole"
   kind "ConsoleApp"
   language "C++"
   targetdir "build/%{cfg.buildcfg}"

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"