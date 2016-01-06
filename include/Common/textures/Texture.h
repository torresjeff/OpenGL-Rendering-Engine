#pragma once

#include "TextureType.h"
#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Texture
{
	GLuint id;
	std::string type;
	aiString path;
};

