include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Minecraft"
	architecture "x86_64"
	startproject "Minecraft"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Minecraft/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Minecraft/vendor/Glad/include"
IncludeDir["glm"] = "%{wks.location}/Minecraft/vendor/glm"
IncludeDir["stb"] = "%{wks.location}/Minecraft/vendor/stb"

group "Dependencies"
	include "vendor/premake"
	include "Minecraft/vendor/GLFW"
	include "Minecraft/vendor/Glad"
group ""

include "Minecraft"
