#pragma once

#include "Window.h"

namespace Minecraft
{
	class Application
	{
	public:
		Application();
		void Run();

		Window& GetWindow() { return m_Window; }
		static Application& Get() { return *s_Instance; }
	private:
		Window m_Window;
		static Application* s_Instance;
	};
}
