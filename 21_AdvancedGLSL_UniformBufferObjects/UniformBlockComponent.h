#pragma once

#include <Common/Common.h>

class UniformBlockComponent : public DrawableGameComponent
{
public:
	UniformBlockComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderCubemap;
	GLuint mContainerVAO, mContainerVBO, mCubemap, mCubemapVAO, mCubemapVBO, mUniformBufferObject;
	std::vector<GLfloat> mContainerVertices, mSkyboxVertices;
	std::vector<char*> mTextureNames;
	GLuint mTextureDiffuse, mTextureSpecular;
	std::vector<glm::vec3> mCubePositions;
	std::vector<glm::vec3> mPointLightPositions;
};
