#pragma once

namespace Minecraft
{
	enum class ShaderType
	{
		VERTEX = 0, FRAGMENT
	};

	class Shader
	{
	public:
		Shader() = default;

		void Add(const char* shaderSource, ShaderType type);
		void Compile();

		void Bind();
		void Unbind();

	private:
		uint32_t m_ProgramID;
		std::vector<uint32_t> m_ShaderIDs;
	};

}
