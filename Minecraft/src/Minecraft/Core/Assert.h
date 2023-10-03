#pragma once

#include "Log.h"

#ifdef MINECRAFT_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define MINECRAFT_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { MINECRAFT##type##ERROR(msg, __VA_ARGS__); __debugbreak(); } }
#define MINECRAFT_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MINECRAFT_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define MINECRAFT_INTERNAL_ASSERT_NO_MSG(type, check) MINECRAFT_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define MINECRAFT_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define MINECRAFT_INTERNAL_ASSERT_GET_MACRO(...) EXPAND_MACRO( MINECRAFT_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MINECRAFT_INTERNAL_ASSERT_WITH_MSG, MINECRAFT_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define ASSERT(...) EXPAND_MACRO( MINECRAFT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define CORE_ASSERT(...) EXPAND_MACRO( MINECRAFT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define ASSERT(...)
#define CORE_ASSERT(...)
#endif
