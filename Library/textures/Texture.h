#pragma once

#include "TextureType.h"
#include <GL/glew.h>

struct Texture
{
	GLuint id;
	TextureType type;
	std::string path;
};

