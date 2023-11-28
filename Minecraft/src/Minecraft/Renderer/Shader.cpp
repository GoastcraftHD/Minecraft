#include "MinecraftPCH.h"
#include "Shader.h"

#include <fstream>
#include <glad/glad.h>

namespace Minecraft
{
	std::string ShaderTypeToString(ShaderType type)
	{
		switch (type)
		{
			case ShaderType::VERTEX: return "Vertex";
			case ShaderType::FRAGMENT: return "Fragment";
			default: return "Unknown";
		}
	}

	GLenum ShaderTypeToGLenum(ShaderType type)
	{
		switch (type)
		{
			case ShaderType::VERTEX: return GL_VERTEX_SHADER;
			case ShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
			default: return 0;
		}
	}

	std::string ReadFile(const char* filePath)
	{
		std::string result;
		std::ifstream in(filePath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
				in.close();
			}
			else
			{
				std::cerr << "Could not read from file " << filePath;
			}
		}
		else
		{
			std::cerr << "Could not open file " << filePath;
		}

		return result;
	}

	void Shader::Add(const char* shaderPath, ShaderType type)
	{
		std::string shaderSrc = ReadFile(shaderPath);
		const char* shaderCSrc = shaderSrc.c_str();

		uint32_t shader = glCreateShader(ShaderTypeToGLenum(type));
		glShaderSource(shader, 1, &shaderCSrc, nullptr);
		glCompileShader(shader);

		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::cerr << "Error in " << ShaderTypeToString(type) << " shader: " << infoLog << std::endl;
		}

		ShaderIDs.emplace_back(shader);
	}

	void Shader::Compile()
	{
		ProgramID = glCreateProgram();

		for (uint32_t shaderID : ShaderIDs)
		{
			glAttachShader(ProgramID, shaderID);
		}

		glLinkProgram(ProgramID);

		int success;
		char infoLog[512];
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(ProgramID, 512, nullptr, infoLog);
			std::cerr << "Error in shader program: " << infoLog << std::endl;
		}
	}

	void Shader::Bind()
	{
		glUseProgram(ProgramID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}
}
