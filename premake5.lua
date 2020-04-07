workspace "Klib"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Klib/vendor/GLFW/include"

include "Klib/vendor/GLFW"

project "Klib"
	location "Klib"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "klpch.h"
	pchsource "Klib/src/klpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KL_PLATFORM_WINDOWS",
			"KL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Klib/vendor/spdlog/include",
		"Klib/src"
	}

	links
	{
		"Klib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KL_DIST"
		optimize "On"