#pragma once

#include "Window.h"

namespace Minecraft
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		Window m_Window;
	};
}
