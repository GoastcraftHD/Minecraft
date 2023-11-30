#include "MinecraftPCH.h"
#include "Camera.h"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

namespace Minecraft
{
	void Camera::Update(uint32_t shaderID)
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), Position)
							* glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.x), glm::vec3(0.0f, 1.0f, 0.0f))
							* glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.y), glm::vec3(1.0f, 0.0f, 0.0f))
							* glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		m_ViewMatrix = glm::inverse(transform);//glm::lookAt(Position, Position + Orientation, Up);
		m_ProjectionMatrix = glm::perspective(glm::radians(FOV), (float)(Width / Height), NearClippingPlane, FarClippingPlane);

		uint32_t viewLoc = glGetUniformLocation(shaderID, "uViewProjection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(m_ProjectionMatrix * m_ViewMatrix));
	}
}
