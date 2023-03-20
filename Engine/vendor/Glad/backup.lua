project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs {
		"include"
	}


	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Development"
		defines "ENGINE_DEVELOPMENT"
		runtime "Release"
		optimize "On"

	filter "configurations:Ship"
		defines "ENGINE_SHIP"
		runtime "Release"
		optimize "On"