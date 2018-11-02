#include "shader_s.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmetCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open file
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderSteam;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderSteam << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmetCode = fShaderSteam.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	auto vShaderCode = vertexCode.c_str();
	auto fShaderCode = fragmetCode.c_str();
	// 2. compile
	unsigned int vertex, fragment;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");
	// fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	// 3. shader program
	m_nId = glCreateProgram();
	glAttachShader(m_nId, vertex);
	glAttachShader(m_nId, fragment);
	glLinkProgram(m_nId);
	CheckCompileErrors(m_nId, "PROGRAM");

	// 4. delete the shader as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
	glDeleteProgram(m_nId);
}

void Shader::Use()
{
	glUseProgram(m_nId);
}

void Shader::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_nId, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(m_nId, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(m_nId, name.c_str()), value);
}

void Shader::Set1iv(const std::string &name, int count, int* value) const
{
	glUniform1iv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set2iv(const std::string &name, int count, int* value) const
{
	glUniform2iv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set3iv(const std::string &name, int count, int* value) const
{
	glUniform3iv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set4iv(const std::string &name, int count, int* value) const
{
	glUniform4iv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set1fv(const std::string &name, int count, float* value) const
{
	glUniform1fv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set2fv(const std::string &name, int count, float* value) const
{
	glUniform2fv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set3fv(const std::string &name, int count, float* value) const
{
	glUniform3fv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::Set4fv(const std::string &name, int count, float* value) const
{
	glUniform4fv(glGetUniformLocation(m_nId, name.c_str()), count, value);
}

void Shader::SetMt2fv(const std::string &name, int count, unsigned char transpose, float* value) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_nId, name.c_str()), count, transpose, value);
}

void Shader::SetMt3fv(const std::string &name, int count, unsigned char transpose, float* value) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_nId, name.c_str()), count, transpose, value);
}

void Shader::SetMt4fv(const std::string &name, int count, unsigned char transpose, float* value) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_nId, name.c_str()), count, transpose, value);
}

void Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	} 
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}
