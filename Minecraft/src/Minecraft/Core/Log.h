#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

#include "Core.h"

namespace Minecraft
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

#define MINECRAFT_CORE_TRACE(...) ::Minecraft::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MINECRAFT_CORE_INFO(...) ::Minecraft::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MINECRAFT_CORE_WARN(...) ::Minecraft::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MINECRAFT_CORE_ERROR(...) ::Minecraft::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MINECRAFT_CORE_CRITICAL(...) ::Minecraft::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define MINECRAFT_TRACE(...) ::Minecraft::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MINECRAFT_INFO(...) ::Minecraft::Log::GetClientLogger()->info(__VA_ARGS__)
#define MINECRAFT_WARN(...) ::Minecraft::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MINECRAFT_ERROR(...) ::Minecraft::Log::GetClientLogger()->error(__VA_ARGS__)
#define MINECRAFT_CRITICAL(...) ::Minecraft::Log::GetClientLogger()->critical(__VA_ARGS__)
