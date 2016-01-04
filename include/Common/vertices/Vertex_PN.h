#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Vertex that contains Position and Normal
struct Vertex_PN
{
	glm::vec3 position;
	glm::vec3 normal;
};
