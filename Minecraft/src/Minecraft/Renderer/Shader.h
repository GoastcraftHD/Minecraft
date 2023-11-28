#pragma once

//TODO Needs a total rewrite!!!!!!

namespace Minecraft
{
	enum class ShaderType
	{
		VERTEX = 0, FRAGMENT
	};

	class Shader
	{
	public:
		uint32_t ProgramID;
		std::vector<uint32_t> ShaderIDs;

		Shader() = default;

		void Add(const char* shaderSource, ShaderType type);
		void Compile();

		void Bind();
		void Unbind();
	};

}
