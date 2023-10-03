#pragma once

namespace Minecraft
{
	class Texture
	{
	public:
		Texture() = default;
		Texture(const char* imagePath);
		Texture(void* data, uint32_t width, uint32_t height);

		void Bind();
		void Unbind();

		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }
		uint32_t GetRendererID() const { return m_RendererID; }
	private:
		uint32_t m_RendererID;
		uint32_t m_Width;
		uint32_t m_Height;
	};
}
