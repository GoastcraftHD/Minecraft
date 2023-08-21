#pragma once

#ifdef MINECRAFT_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	#include <Windows.h>
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
