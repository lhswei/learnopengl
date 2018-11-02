#ifndef _SHADER_S_H_
#define _SHADER_S_H_

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~ Shader();
	void Use();

	void SetBool(const std::string &name, bool value) const;

	void SetInt(const std::string &name, int value) const;

	void SetFloat(const std::string &name, float value) const;

	void Set1iv(const std::string &name, int count, int* value) const;
	void Set2iv(const std::string &name, int count, int* value) const;
	void Set3iv(const std::string &name, int count, int* value) const;
	void Set4iv(const std::string &name, int count, int* value) const;
	void Set1fv(const std::string &name, int count, float* value) const;
	void Set2fv(const std::string &name, int count, float* value) const;
	void Set3fv(const std::string &name, int count, float* value) const;
	void Set4fv(const std::string &name, int count, float* value) const;
	void SetMt2fv(const std::string &name, int count, unsigned char transpose, float* value) const;
	void SetMt3fv(const std::string &name, int count, unsigned char transpose, float* value) const;
	void SetMt4fv(const std::string &name, int count, unsigned char transpose, float* value) const;

	void SetMat4(const std::string &name, float* value) const { SetMt4fv(name, 1, GL_FALSE, value); }
private:
	void CheckCompileErrors(unsigned int shader, std::string type);

public:
	unsigned int m_nId;

};

#endif //_SHADER_S_H_