#pragma once

#include "MeshComponent.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "..\exceptions\GameException.h"

class ModelComponent : DrawableGameComponent
{
public:
	ModelComponent(std::string path);
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	void LoadModel(const std::string& path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	MeshComponent ProcessMesh(aiMesh* mesh, const aiScene* scene);


	std::vector<MeshComponent> mMeshes;
	Shader mShader;
};