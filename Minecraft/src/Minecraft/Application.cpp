#include "MinecraftPCH.h"
#include "Application.h"

#include "Minecraft/Renderer/Shader.h"
#include "Core/Input.h"

#include <glad/glad.h>

namespace Minecraft
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
		: m_Window("Minecraft", 1920, 1080)
	{
		s_Instance = this;
	}

	void Application::Run()
	{
		float vertices[3 * 3] =
		{
			-0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};
		
		uint32_t VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		uint32_t VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		Shader shader;
		shader.Add("assets/shaders/Default.vert", ShaderType::VERTEX);
		shader.Add("assets/shaders/Default.frag", ShaderType::FRAGMENT);

		shader.Compile();
		
		while (true)
		{
			glfwPollEvents();
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			shader.Bind();
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			if (Input::IsKeyPressed(KeyCode::E))
				MINECRAFT_CORE_TRACE("Test");

			glfwSwapBuffers(m_Window.GetNativeWindow());
		}
	}

}
