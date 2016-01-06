#include "ModelComponent.h"
#include <SOIL\SOIL.h>
using namespace Assimp;

ModelComponent::ModelComponent(Application& application, std::string path/*, std::initializer_list<std::string> textures*/)
	: DrawableGameComponent(application)
{
	LoadModel(path);
}

ModelComponent::ModelComponent(Application & application, Camera& camera, std::string path)
	: DrawableGameComponent(application, camera)
{
	LoadModel(path);
}

ModelComponent::ModelComponent(Application& application, Camera& camera, std::string path, Shader shader)
	: DrawableGameComponent(application, camera), mShader(shader)
{
	LoadModel(path);
}

void ModelComponent::Initialize()
{
	for (unsigned int i = 0; i < mMeshes.size(); ++i)
	{
		mMeshes[i].SetShader(mShader);
		mMeshes[i].Initialize();
	}
}

void ModelComponent::Draw(float DeltaSeconds)
{
	//Model
	GLint modelLocation = glGetUniformLocation(mShader.Program(), "model");
	if (modelLocation == -1)
	{
		std::cout << "modelLocation == -1\n";
	}

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

	//View
	GLint viewLocation = glGetUniformLocation(mShader.Program(), "view");
	if (viewLocation == -1)
	{
		std::cout << "viewLocation == -1\n";
	}
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));

	//Projection
	GLint projectionLocation = glGetUniformLocation(mShader.Program(), "projection");
	if (projectionLocation == -1)
	{
		std::cout << "projectionLocation == -1\n";
	}
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));

	for (auto& mesh : mMeshes)
	{
		mesh.Draw(DeltaSeconds);
	}
}

void ModelComponent::LoadModel(const std::string& path)
{
	Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	//Check if it loaded correctly
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		throw GameException("Could not load " + path + ": " + importer.GetErrorString());
	}

	mDirectory = path.substr(0, path.find_last_of('/'));
	ProcessNode(scene->mRootNode, scene);
}

void ModelComponent::ProcessNode(aiNode* node, const aiScene* scene)
{
	
	for (unsigned int i = 0; i < node->mNumMeshes; ++i)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		mMeshes.push_back(ProcessMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; ++i)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

MeshComponent ModelComponent::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex_PNT> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	//Process vertex information (position, normals, and texCoords)
	for (GLuint i = 0; i < mesh->mNumVertices; ++i)
	{
		Vertex_PNT vertex;

		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoords(0.0f);

		position.x = mesh->mVertices[i].x;
		position.y = mesh->mVertices[i].y;
		position.z = mesh->mVertices[i].z;
		vertex.position = position;

		normal.x = mesh->mNormals[i].x;
		normal.y = mesh->mNormals[i].y;
		normal.z = mesh->mNormals[i].z;
		vertex.normal = normal;

		//Check if the mesh contains texture coordinates
		if (mesh->mTextureCoords[0])
		{
			texCoords.x = mesh->mTextureCoords[0][i].x;
			texCoords.y = mesh->mTextureCoords[0][i].y;
		}
		vertex.texCoords = texCoords; //If the mesh didn't have texCoords, then we set them to (0, 0) (the value we initialized the vec2 to).

		vertices.push_back(vertex);
	}

	//Process the faces (to get the indices)
	for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j) // Process the indices that make up the face
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	
	//Check if the mesh has materials
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		std::vector<Texture> diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE);
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		std::vector<Texture> specularMaps = LoadMaterialTextures(material, aiTextureType_SPECULAR);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		std::vector<Texture> normalMaps = LoadMaterialTextures(material, aiTextureType_HEIGHT);
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	}
	
	return MeshComponent(*mApplication, *mCamera, vertices, indices, textures);
}

std::vector<Texture> ModelComponent::LoadMaterialTextures(aiMaterial* material, aiTextureType type)
{
	std::vector<Texture> textures;
	TextureType texType;
	switch (type)
	{
	case aiTextureType_DIFFUSE:
		texType = TextureType::TEXTURE_DIFFUSE;
		break;
	case aiTextureType_SPECULAR:
		texType = TextureType::TEXTURE_SPECULAR;
		break;
	case aiTextureType_AMBIENT:
		texType = TextureType::TEXTURE_AMBIENT;
		break;
	case aiTextureType_HEIGHT:
		texType = TextureType::TEXTURE_NORMAL;
		break;
	}

	for (GLuint i = 0; i < material->GetTextureCount(type); ++i)
	{
		aiString str;
		material->GetTexture(type, i, &str);

		int textureIndex;
		if (IsTextureLoaded(mDirectory + "/" + std::string(str.C_Str()), &textureIndex)) //We check if the texture is already loaded, if it is then we use that one instead of loading it again.
		{
			textures.push_back(mLoadedTextures[textureIndex]);
		}
		else
		{
			Texture texture;
			texture.id = LoadTextureFromFile(str.C_Str(), mDirectory);
			texture.type = texType;
			texture.path = mDirectory + "/" + std::string(str.C_Str());
			textures.push_back(texture);
			mLoadedTextures.push_back(texture); //Add to loaded textures
		}
	}
	

	return textures;
}

GLuint ModelComponent::LoadTextureFromFile(const char* name, std::string directory)
{
	std::string path = directory + "/" + std::string(name);
	GLuint texture;
	int width, height, channels;
	
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	unsigned char* data = SOIL_load_image(path.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);
	GLenum format = (channels == 3) ? GL_RGB  : GL_RGBA; //We're assuming images will only have either 3 or 4 channels.
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(data);

	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}

bool ModelComponent::IsTextureLoaded(std::string path, int* index)
{
	for (unsigned int i = 0; i < mLoadedTextures.size(); ++i)
	{
		if (mLoadedTextures[i].path == path)
		{
			std::cout << "Texture " << path << " is already loaded\n";
			*index = i;
			return true;
		}
	}

	std::cout << "Texture " << path << " is NOT loaded\n";
	*index = -1;
	return false;
}
