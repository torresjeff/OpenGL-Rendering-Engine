#include "ModelComponent.h"


ModelComponent::ModelComponent(std::string path)
{
	LoadModel(path);
}

void ModelComponent::LoadModel(const std::string & path)
{
	using namespace Assimp;
	Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	//Check if it loaded correctly
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		throw GameException("Could not load " + path + ": " + importer.GetErrorString());
	}

	ProcessNode(scene->mRootNode, scene);

}

void ModelComponent::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (int i = 0; i < scene->mNumMeshes; ++i)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		mMeshes.push_back(ProcessMesh(mesh, scene));
	}

	for (int i = 0; i < node->mNumChildren; ++i)
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
		normal.x = mesh->mNormals[i].z;
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
	for (GLuint i = 0; i < mesh->mNumFaces; ++i)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; ++j) // Process the indices that make up the face
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	
	//Check if the mesh has materials
	

	return MeshComponent(*mApplication, vertices, indices, textures);
}
