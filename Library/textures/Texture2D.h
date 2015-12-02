#pragma once

#include <string>
#include <SOIL/SOIL.h>
#include <GL/glew.h>

class Texture2D
{
public:
	Texture2D();
	Texture2D(GLuint shaderProgram);
	Texture2D(GLuint shaderProgram, std::string path);
	virtual ~Texture2D();

	void LoadTexture(std::string path);
	void BindTexture(GLenum textureUnit);
	void UnbindTexture();
	void FreeImageData();
	void GenerateTexture(GLint internalFormat, GLenum imageFormat, GLenum type);
	void GenerateMipmaps();

	//Getters/Setters
	unsigned char* GetData() const;
	int GetWidth() const;
	int GetHeight() const;
	void SetProgram(GLuint program);
	void SetSampler2D(std::string name);
	void SetTextureParameter(GLenum pname, GLint param);
protected:
	virtual void Initialize();
protected:
	GLint mImageWidth, mImageHeight, mLocation;
	unsigned char* mData;
	GLuint mTexture;
	GLuint mProgram;
};