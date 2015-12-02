#include "Texture2D.h"

Texture2D::Texture2D()
{
	Initialize();
}

Texture2D::Texture2D(GLuint shaderProgram)
{
	mProgram = shaderProgram;
	Initialize();
}

Texture2D::Texture2D(GLuint shaderProgram, std::string path)
{
	mProgram = shaderProgram;
	Initialize();
	LoadTexture(path);
}

void Texture2D::Initialize()
{
	glGenTextures(1, &mTexture);
	mLocation = 0;
	mData = nullptr;
	mImageWidth = 0;
	mImageHeight = 0;
}

Texture2D::~Texture2D()
{
	if (mData)
	{
		SOIL_free_image_data(mData);
	}
}

void Texture2D::LoadTexture(std::string path)
{
	mData = SOIL_load_image(path.c_str(), &mImageWidth, &mImageHeight, 0, SOIL_LOAD_RGB);
}

void Texture2D::BindTexture(GLenum textureUnit)
{
	glActiveTexture(textureUnit);
	glBindTexture(GL_TEXTURE_2D, mTexture);
}

void Texture2D::UnbindTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::FreeImageData()
{
	if (mData)
	{
		SOIL_free_image_data(mData);
		mData = nullptr;
	}
}

void Texture2D::GenerateTexture(GLint internalFormat, GLenum format, GLenum type)
{
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, mImageWidth, mImageHeight, 0, format, type, mData);
}

void Texture2D::GenerateMipmaps()
{
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture2D::SetTextureParameter(GLenum pname, GLint param)
{
	glTexParameteri(GL_TEXTURE_2D, pname, param);
}

unsigned char * Texture2D::GetData() const
{
	return mData;
}

int Texture2D::GetWidth() const
{
	return mImageWidth;
}

int Texture2D::GetHeight() const
{
	return mImageHeight;
}

void Texture2D::SetProgram(GLuint program)
{
	mProgram = program;
}

void Texture2D::SetTextureUnitUniform(std::string name, int value)
{
	mLocation = value;
	glUniform1i(glGetUniformLocation(mProgram, name.c_str()), value);
}


