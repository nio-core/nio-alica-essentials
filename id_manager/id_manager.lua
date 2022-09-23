-- premake5.lua

workspace "essentials"
   configurations { "Debug", "Release" }
--   postbuildmessage "Copying dependencies..."
 --  postbuildcommands { "cp -R grid_sim/textures  bin/%{cfg.buildcfg}" }
   

project "id_manager"
   kind "StaticLib"
   language "C++"
   cppdialect "C++14"
   targetdir "bin/%{cfg.buildcfg}"

   libdirs { 
      --"../fsystem/**",
      --"../../googletest/build/**",
      os.findlib("uuid")
     }

   links { 
      "uuid" 
   }

   includedirs {
      "include", 
      --"../../googletest/googletest/include" 
   }
   
   files {      
      "include/**.h", 
      "src/**.cpp",  
   }
   
   excludes {
      "src/test/**",
   }

   -- linkoptions {"-pthread", "-lsfml-graphics", "-lsfml-window", "-lsfml-system" }
       
   --filter "files:**.png"
   --   buildaction "Copy"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
   
--    postbuildcommands { "cp grid_sim/textures/*.* bin/Debug/textures/" }
--    postbuildmessage "Copying dependencies..."
--    os.copyfile("/textures", "%{targetdir}/textures")

-- if _ACTION == "clean" then
--		os.rmdir("bin")
--		os.rmdir("build")
-- end


