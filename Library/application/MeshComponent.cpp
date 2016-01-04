#include "MeshComponent.h"

MeshComponent::MeshComponent(Application& application, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
	: DrawableGameComponent(application), mVertices(vertices), mIndices(indices), mTextures(textures)
{}

void MeshComponent::Initialize()
{
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);


	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex_PNT), &mVertices[0], GL_STATIC_DRAW);
	//Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, position)));
	//Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, normal)));
	//Vertex texture coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, texCoords)));
	
	//Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(GLuint), &mIndices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void MeshComponent::Update(float DeltaSeconds)
{
}

void MeshComponent::SetShader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	mShader = Shader(vertexShaderPath, fragmentShaderPath);
}
