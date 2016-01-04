#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Vertex that contains Position, Normal, and TexCoords
struct Vertex_PNT
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};
