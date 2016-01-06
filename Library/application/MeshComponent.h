#pragma once

#include "DrawableGameComponent.h"
#include <vector>
#include "..\shaders\shader.h"
#include "..\textures\Texture.h"
#include "..\vertices\Vertex_PNT.h"
#include <iostream>


class MeshComponent : public DrawableGameComponent
{
public:
	MeshComponent(Application& application, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	MeshComponent(Application& application, Camera& camera, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;

	void SetShader(Shader shader);
private:
	GLuint mVAO, mVBO, mIBO;
	Shader mShader;
	std::vector<Vertex_PNT> mVertices;
	std::vector<GLuint> mIndices;
	std::vector<Texture> mTextures;
};
