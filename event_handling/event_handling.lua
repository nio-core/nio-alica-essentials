-- premake5.lua

workspace "essentials"
   configurations { "Debug", "Release" }

project "event_handling"
   kind "StaticLib"
   language "C++"
   cppdialect "C++14"
   targetdir "bin/%{cfg.buildcfg}"

   libdirs { 
      os.findlib("uuid")
     }

   links { "uuid" }

   includedirs {
      "include", 
   }
   
   files {
      "include/**.h", 
      "src/**.cpp", 
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
   


