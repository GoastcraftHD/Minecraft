#include "MinecraftPCH.h"
#include "Camera.h"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

namespace Minecraft
{
	void Camera::Update(uint32_t shaderID)
	{
		m_ViewMatrix = glm::lookAt(Position, Position + Orientation, Up);
		m_ProjectionMatrix = glm::perspective(glm::radians(FOV), (float)(Width / Height), NearClippingPlane, FarClippingPlane);

		uint32_t viewLoc = glGetUniformLocation(shaderID, "uViewProjection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(m_ProjectionMatrix * m_ViewMatrix));
	}
}
