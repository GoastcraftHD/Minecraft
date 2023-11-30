#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Minecraft
{
	class Camera
	{
	public:
		void Update(uint32_t shaderID);

		float FOV = 90.0f;
		uint32_t Width = 1920;
		uint32_t Height = 1080;
		float NearClippingPlane = 0.1f;
		float FarClippingPlane = 100.0f;

		glm::vec3 Position = glm::vec3(0.0f, 0.0f, 10.0f);
		glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		//glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
		//glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	private:
		glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
		glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);
	};
}
