--premake5.lua

workspace "Engine"
	architecture"x64"
	configurations {"Debug", "Development", "Ship"}

	outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	--include dir relative to root folder(sln dir)

	IncludeDir = {}
	IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
	IncludeDir["Glad"] = "Engine/vendor/Glad/include"

	--include the glfw premake files
	include "Engine/vendor/GLFW"
	include "Engine/vendor/Glad"

project "Engine"
	location "Engine"
	kind "SharedLib" --dll
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EnginePCH.h"
	pchsource "Engine/src/EnginePCH.cpp" --for vs


	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

	includedirs {"%{prj.name}/src", "%{prj.name}/vendor/spdlog/include", "%{IncludeDir.GLFW}", "%{IncludeDir.Glad}"}

	links { "GLFW","Glad", "opengl32.lib"}
									  
	filter	"system:windows"		  
		cppdialect "c++17"
		staticruntime"On"
		systemversion "latest"

	defines {"ENGINE_PLATFORM_WINDOWS", "ENGINE_BUILD_DLL", "GLFW_INCLUDE_NONE"}

	--copy engine.dll -> sandbox
	postbuildcommands ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	
	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		buildoptions "/MDd"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		buildoptions "/MDd"
		optimize "On"