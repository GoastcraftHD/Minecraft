project "Minecraft"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "MinecraftPCH.h"
	pchsource "src/MinecraftPCH.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"MINECRAFT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MINECRAFT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MINECRAFT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MINECRAFT_DIST"
		runtime "Release"
		optimize "on"
