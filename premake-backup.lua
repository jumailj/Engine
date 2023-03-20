--premake5.lua

workspace "Engine"
	architecture"x64"
	startproject "Sandbox"
	configurations {"Debug", "Development", "Ship"}

	outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	--include dir relative to root folder(sln dir)

	IncludeDir = {}
	IncludeDir["GLFW"]  = "Engine/vendor/GLFW/include"
	IncludeDir["Glad"]  = "Engine/vendor/Glad/include"
	IncludeDir["ImGui"] = "Engine/vendor/imgui"
	IncludeDir["glm"] =   "Engine/vendor/glm"

	--include the glfw premake files
	include "Engine/vendor/GLFW"
	include "Engine/vendor/Glad"
	include "Engine/vendor/imgui"
	

project "Engine"
	location "Engine"
	kind "SharedLib" --dll
	language "C++"
	staticruntime "off"
	cppdialect "c++17"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EnginePCH.h"
	pchsource "Engine/src/EnginePCH.cpp" --for vs


	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp", "%{prj.name}/vendor/glm/glm/**.hpp", "%{prj.name}/vendor/glm/glm/**.ini"}

	includedirs {"%{prj.name}/src", "%{prj.name}/vendor/spdlog/include", "%{IncludeDir.GLFW}", "%{IncludeDir.Glad}","%{IncludeDir.ImGui}", "%{IncludeDir.glm}"}

	links { "GLFW","Glad","ImGui", "opengl32.lib"}
									  

	defines {"ENGINE_PLATFORM_WINDOWS", "ENGINE_BUILD_DLL", "GLFW_INCLUDE_NONE"}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	--copy engine.dll -> sandbox
	
	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		runtime "Release"
		optimize "on"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "consoleApp"
	language "C++"
	staticruntime "off"
	cppdialect "c++17"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

	includedirs {"Engine/vendor/spdlog/include", "Engine/src","Engine/vendor", "%{IncludeDir.glm}"}

	links {"Engine"}

	defines {"ENGINE_PLATFORM_WINDOWS"}

	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		runtime "Release"
		optimize "on"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		runtime "Release"
		optimize "on"