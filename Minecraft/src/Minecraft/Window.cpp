#include "MinecraftPCH.h"
#include "Window.h"

#include "glad/glad.h"

namespace Minecraft
{
	Window::Window(std::string title, int width, int height)
	{
		int initialized = glfwInit();

		CORE_ASSERT(initialized, "Failed to initialize GLFW!");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_NativeWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		CORE_ASSERT(m_NativeWindow, "Failed to create window!");

		glfwMakeContextCurrent(m_NativeWindow);

		int glLoaderInitialized = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		CORE_ASSERT(glLoaderInitialized, "Failed to initialize glad");

		glViewport(0, 0, width, height);

		MINECRAFT_CORE_INFO("Created window '{0}' ({1}x{2})", title.c_str(), width, height);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_IsVSync = enabled;
	}
}
