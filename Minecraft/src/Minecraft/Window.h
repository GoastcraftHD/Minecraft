#pragma once

#include "GLFW/glfw3.h"

namespace Minecraft
{
	class Window
	{
	public:
		Window(std::string name, int width, int height);
		~Window();

		GLFWwindow* GetNativeWindow() { return m_NativeWindow; }

		void SetVSync(bool enabled);
		bool IsVSync() const { return m_IsVSync; }
	private:
		bool m_IsVSync = false;
		GLFWwindow* m_NativeWindow;
	};
}
