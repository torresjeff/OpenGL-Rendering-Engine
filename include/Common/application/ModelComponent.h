#pragma once

#include "MeshComponent.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "..\exceptions\GameException.h"

class ModelComponent : public DrawableGameComponent
{
public:
	ModelComponent(Application& application, std::string path);
	ModelComponent(Application& application, Camera& camera, std::string path);
	ModelComponent(Application& application, Camera& camera, std::string path, Shader shader);
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	void LoadModel(const std::string& path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	MeshComponent ProcessMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> LoadMaterialTextures(aiMaterial* material, aiTextureType type);
	GLuint LoadTextureFromFile(const char* name, std::string directory);
	bool IsTextureLoaded(std::string path, int* index);

	std::string mDirectory;
	std::vector<MeshComponent> mMeshes;
	std::vector<Texture> mLoadedTextures;
	Shader mShader;
};