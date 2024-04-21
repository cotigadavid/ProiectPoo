workspace "Sistem Bancar"
	architecture "x64"
	startproject "Banca"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Banca"
	location "Banca"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/Headers/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/Headers",
	}


	filter "configurations:Debug"
		defines "Separ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "Separ_RELEASE"
		runtime "Release"
		optimize "on"

	

