#include "Logger.h"

using namespace std;

bool Logger::RestartGlLog()
{
	ofstream file(GL_LOG_FILE);
	
	if (!file.is_open())
	{
		throw GameException("ERROR: Could not open log file " + std::string(GL_LOG_FILE));
		return false;
	}
	
	time_t now = time(NULL);
	std::string date (ctime(&now));

	file << "LOG\n\nLocal time: " << date << "\n\n";
	file.close();
	return true;
}

bool Logger::LogProgramInfo(GLuint program)
{
	ofstream file(GL_LOG_FILE, ios::app);

	if (!file.is_open())
	{
		throw GameException("ERROR: Could not open log file " + std::string(GL_LOG_FILE));
		return false;
	}

	file << "//----------- SHADER PROGRAM -----------//\n";
	int params = -1;
	int actualLength = 0;

	char log[2048];
	

	glGetProgramiv(program, GL_LINK_STATUS, &params);
	file << "GL_LINK_STATUS = " << params << "\n";

	glGetProgramiv(program, GL_ATTACHED_SHADERS, &params);
	file << "GL_ATTACHED_SHADERS = " << params << "\n";

	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &params);
	file << "GL_ACTIVE_ATTRIBUTES = " << params << "\n";

	for (GLuint i = 0; i < (GLuint)params; ++i)
	{
		char name[64];
		int maxLength = 64;
		int size = 0;
		GLenum type;
		
		glGetActiveAttrib(program, i, maxLength, &actualLength, &size, &type, name);

		//If it's an array
		if (size > 1)
		{
			for (int j = 0; j < size; ++j)
			{
				std::stringstream longName;
				longName << name << "[" << j << "]";

				GLint location = glGetAttribLocation(program, longName.str().c_str());
				file << i + 1 << ") type: " << GlTypeToString(type) << ", name: " << longName.str() << ", location: " << location << "\n";
			}
		}
		else
		{
			GLint location = glGetAttribLocation(program, name);
			file << i + 1 << ") type: " << GlTypeToString(type) << ", name: " << name << ", location: " << location << "\n";
		}
	}

	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &params);
	file << "GL_ACTIVE_UNIFORMS = " << params << "\n";
	
	for (GLuint i = 0; i < (GLuint)params; ++i)
	{
		char name[64];
		int maxLength = 64;
		int size = 0;
		GLenum type;

		glGetActiveUniform(program, i, maxLength, &actualLength, &size, &type, name);

		//If it's an array
		if (size > 1)
		{
			for (int j = 0; j < size; ++j)
			{
				std::stringstream longName;
				longName << name << "[" << j << "]";

				GLint location = glGetUniformLocation(program, longName.str().c_str());
				file << i + 1 << ") type: " << GlTypeToString(type) << ", name: " << longName.str() << ", location: " << location << "\n";
			}
		}
		else
		{
			GLint location = glGetUniformLocation(program, name);
			file << i + 1 << ") type: " << GlTypeToString(type) << ", name: " << name << ", location: " << location << "\n";
		}
	}


	file.close();

	
	return true;
}

std::string Logger::GlTypeToString(GLenum type)
{
	switch (type)
	{
	case GL_BOOL: return "bool";
	case GL_INT: return "int";
	case GL_FLOAT: return "float";
	case GL_FLOAT_VEC2: return "vec2";
	case GL_FLOAT_VEC3: return "vec3";
	case GL_FLOAT_VEC4: return "vec4";
	case GL_FLOAT_MAT2: return "mat2";
	case GL_FLOAT_MAT3: return "mat3";
	case GL_FLOAT_MAT4: return "mat4";
	case GL_SAMPLER_1D: return "sampler1D";
	case GL_SAMPLER_2D: return "sampler2D";
	case GL_SAMPLER_3D: return "sampler3D";
	case GL_SAMPLER_CUBE: return "samplerCube";
	case GL_SAMPLER_2D_SHADOW: return "sampler2DShadow";
	default: break;
	}
	return "other";
}

bool Logger::LogValidateError(GLuint program)
{
	ofstream file(GL_LOG_FILE, ios::app);

	if (!file.is_open())
	{
		throw GameException("ERROR: Could not open log file " + std::string(GL_LOG_FILE));
		return false;
	}

	file << "\nInvalid program " + std::to_string(program) + ":\n";
	char log[2048];
	glGetProgramInfoLog(program, 2048, NULL, log);
	file << "Program info log for GL index " << program << ":\n" << log << "\n";
	file.close();

	return true;
}
