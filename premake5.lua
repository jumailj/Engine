--premake5.lua

workspace "Engine"
	architecture"x64"
	configurations {"Debug", "Development", "Ship"}

	outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	--include dir relative to root folder(sln dir)

	IncludeDir = {}
	IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"

	--include the glfw premake files
	include "Engine/vendor/GLFW"

project "Engine"
	location "Engine"
	kind "SharedLib" --dll
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EnginePCH.h"
	pchsource "Engine/src/EnginePCH.cpp" --for vs


	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

	includedirs {"%{prj.name}/src", "%{prj.name}/vendor/spdlog/include", "%{IncludeDir.GLFW}"}

	links { "GLFW", "opengl32.lib"}
									  
	filter	"system:windows"		  
		cppdialect "c++17"
		staticruntime"On"
		systemversion "latest"

	defines {"ENGINE_PLATFORM_WINDOWS", "ENGINE_BUILD_DLL"}

	--copy engine.dll -> sandbox
	postbuildcommands ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	
	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		optimize "On"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "consoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

	includedirs {"Engine/vendor/spdlog/include", "Engine/src"}

	links {"Engine"}

	filter	"system:windows"
		cppdialect "c++17"
		staticruntime"On"
		systemversion "latest"

	defines {"ENGINE_PLATFORM_WINDOWS"}


	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		optimize "On"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		optimize "On"