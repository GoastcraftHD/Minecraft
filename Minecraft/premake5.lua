project "Minecraft"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "MinecraftPCH.h"
	pchsource "src/MinecraftPCH.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
		"vendor/stb/**.h",
		"vendor/stb/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "files:vendor/**.cpp"
		flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"MINECRAFT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
			"MINECRAFT_DEBUG",
			"MINECRAFT_ENABLE_ASSERTS"
		}

		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines
		{
			"MINECRAFT_RELEASE",
			"MINECRAFT_ENABLE_ASSERTS"
		}

		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MINECRAFT_DIST"
		runtime "Release"
		optimize "on"
