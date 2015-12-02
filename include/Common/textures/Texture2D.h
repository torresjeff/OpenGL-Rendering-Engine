#pragma once

#include <string>
#include <SOIL/SOIL.h>

class Texture2D
{
public:
	Texture2D();
	Texture2D(std::string path);
	virtual ~Texture2D();

	void LoadTexture(std::string path);
	void FreeImageData();

	//Getters/Setters
	unsigned char* GetData() const;
	int GetWidth() const;
	int GetHeight() const;
protected:
	int mImageWidth, mImageHeight;
	unsigned char* mData;
};