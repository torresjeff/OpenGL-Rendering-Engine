#include "shader.h"
#include <vector>
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

#define CHECK_COMPILE_STATUS(shader, success, infoLog); \
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); \
		if (!success) \
		{ \
			glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog); \
			cout << "Error compiling shader: " << infoLog << endl; \
		}

Shader::Shader()
	: mProgram(0)
{}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	GLint success;
	GLchar infoLog[512];
	GLuint vertexShader, fragmentShader;

	std::vector<char> shaderSource;
	ReadShaderFromFile(vertexShaderPath, shaderSource);

	GLchar* sourcePointer = &shaderSource[0];

	//cout << sourcePointer << endl;

	vertexShader = glCreateShader(GL_VERTEX_SHADER); //Creates a vertex shader object and returns a handle to it
	//The glShaderSource function takes the shader object to compile to as its first argument.
	// The second argument specifies how many strings we're passing as source code, which is only one.
	// The third parameter is the actual source code of the vertex shader.
	// The 4th parameter specifies an array of string lengths.
	glShaderSource(vertexShader, 1, &sourcePointer, nullptr); //Attaches our source code to the vertexShader object
	glCompileShader(vertexShader); //Compiles the shader
	CHECK_COMPILE_STATUS(vertexShader, success, infoLog);

	ReadShaderFromFile(fragmentShaderPath, shaderSource);
	sourcePointer = &shaderSource[0];

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &sourcePointer, nullptr);
	glCompileShader(fragmentShader);
	CHECK_COMPILE_STATUS(fragmentShader, success, infoLog);

	mProgram = glCreateProgram(); //Creates a program and returns a handle (ID) to it. We store the program in a member variable called program.

	//We attach the shaders to our created program and link them
	glAttachShader(mProgram, vertexShader);
	glAttachShader(mProgram, fragmentShader);
	glLinkProgram(mProgram);

	glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(mProgram, 512, NULL, infoLog);
		cout << "Error linking program: " << infoLog << endl;
		return;
	}

	//We no longer need the shaders because they are now linked to the program.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::ReadShaderFromFile(std::string shaderPath, std::vector<char>& shaderSource)
{
	std::ifstream file(shaderPath.c_str(), std::ios::binary);
	if (file.bad())
	{
		throw std::exception("Could not open file.");
	}

	file.seekg(0, std::ios::end);
	unsigned int size = (int)file.tellg();

	if (size > 0)
	{
		shaderSource.resize(size);
		file.seekg(0, std::ios::beg);
		file.read(&shaderSource.front(), size);
	}
	//Para que no lea garbage
	shaderSource.push_back('\0');

	file.close();
}

void Shader::UseProgram()
{
	glUseProgram(mProgram);
}
