#pragma once

#include "DrawableGameComponent.h"
#include <vector>
#include "..\shaders\shader.h"
#include "..\textures\Texture.h"
#include "..\vertices\Vertex_PNT.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex {
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

//struct Texture {
//	GLuint id;
//	std::string type;
//	aiString path;
//};

class MeshComponent : public DrawableGameComponent
{
public:
	//MeshComponent(Application& application, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	//MeshComponent(Application& application, Camera& camera, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	MeshComponent(Application& application, std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;


	/*  Functions  */
	void SetShader(Shader shader);

private:
	/*  Render data  */
	/*  Mesh Data  */
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;
	Shader mShader;
	GLuint VAO, VBO, EBO;
};
