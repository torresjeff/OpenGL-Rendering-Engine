#pragma once

#include "DrawableGameComponent.h"
#include <vector>
#include "..\shaders\shader.h"
#include "..\textures\Texture.h"
#include "..\vertices\Vertex_PNT.h"


class MeshComponent : public DrawableGameComponent
{
public:
	MeshComponent(Application& application, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	virtual void Initialize() override;
	virtual void Update(float DeltaSeconds) override;

	void SetShader(std::string vertexShaderPath, std::string fragmentShaderPath);
private:
	GLuint mVAO, mVBO, mIBO;
	std::vector<Vertex_PNT> mVertices;
	std::vector<GLuint> mIndices;
	std::vector<Texture> mTextures;
	Shader mShader;
};
