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

}
