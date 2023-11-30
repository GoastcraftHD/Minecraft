#include "MinecraftPCH.h"
#include "Input.h"

#include "Minecraft/Application.h"

namespace Minecraft
{
	bool Input::IsKeyPressed(KeyCode::Key key)
	{
		int state = glfwGetKey(Application::Get().GetWindow().GetNativeWindow(), key);
		
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	glm::vec2 Input::GetMousePos()
	{
		double xPos, yPos;
		glfwGetCursorPos(Application::Get().GetWindow().GetNativeWindow(), &xPos, &yPos);
		return glm::vec2(xPos, yPos);
	}

	float Input::GetMouseX()
	{
		return GetMousePos().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePos().y;
	}

}
