#include "MeshComponent.h"

MeshComponent::MeshComponent(Application& application, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
	: DrawableGameComponent(application), mVertices(vertices), mIndices(indices), mTextures(textures)
{}

MeshComponent::MeshComponent(Application& application, Camera& camera, std::vector<Vertex_PNT> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
	: DrawableGameComponent(application, camera), mVertices(vertices), mIndices(indices), mTextures(textures)
{}

void MeshComponent::Initialize()
{
	//Generate buffers
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);


	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex_PNT), &mVertices[0], GL_STATIC_DRAW);
	//Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(GLuint), &mIndices[0], GL_STATIC_DRAW);
	//Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, position)));
	//Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, normal)));
	//Vertex texture coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNT), (GLvoid*)(offsetof(Vertex_PNT, texCoords)));
	

	glBindVertexArray(0);
}

void MeshComponent::Draw(float DeltaSeconds)
{
	mShader.UseProgram();
	glBindVertexArray(mVAO);

	GLuint diffuseNumber = 1;
	GLuint specularNumber = 1;
	GLuint normalNumber = 1;


	for (unsigned int i = 0; i < mTextures.size(); ++i)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		std::string textureType;
		
		if (mTextures[i].type == TextureType::TEXTURE_DIFFUSE)
		{
			textureType = "texture_diffuse" + std::to_string(diffuseNumber);
			++diffuseNumber;
		}
		else if (mTextures[i].type == TextureType::TEXTURE_SPECULAR)
		{
			textureType = "texture_specular" + std::to_string(specularNumber);
			++specularNumber;
		}
		else if (mTextures[i].type == TextureType::TEXTURE_NORMAL)
		{
			textureType = "texture_normal" + std::to_string(normalNumber);
			++normalNumber;
		}
		//std::cout << "textureType = " << textureType << "\n";

		//Set texture samplers
		std::string uniformName = /*"material." + */textureType;
		GLint textureTypeLocation = glGetUniformLocation(mShader.Program(), uniformName.c_str());
		if (textureTypeLocation != -1)
		{
			std::cout << uniformName << " found.\n";
			glUniform1i(textureTypeLocation, i);
			glBindTexture(GL_TEXTURE_2D, mTextures[i].id);
		}
		else
		{
			//std::cout << uniformName << " NOT found.\n";
		}
	}
	//glActiveTexture(GL_TEXTURE0);

	
	
	glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

	glBindVertexArray(0);
	glUseProgram(0);
}

void MeshComponent::SetShader(Shader shader)
{
	mShader = shader;
}
