#include "MinecraftPCH.h"
#include "Texture.h"

#include <glad/glad.h>
#include <stb_image.h>

namespace Minecraft
{
	Texture::Texture(const char* imagePath)
	{
		int width, height, channels;
		void* data = stbi_load(imagePath, &width, &height, &channels, 4);

		Texture(data, width, height);
	}

	Texture::Texture(void* data, uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGBA8, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
