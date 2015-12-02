#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>

class Shader
{
public:
	Shader();
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

public:
	void ReadShaderFromFile(std::string shaderPath, std::vector<char>& shaderSource);
	inline GLuint Program() const { return mProgram; }
	void UseProgram();
private:
	GLuint mProgram;
};
