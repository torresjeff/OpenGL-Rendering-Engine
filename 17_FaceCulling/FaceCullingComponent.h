#pragma once

#include <Common/Common.h>

class FaceCullingComponent : public DrawableGameComponent
{
public:
	FaceCullingComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderLight;
	GLuint mVAO, mVBO;
	std::vector<GLfloat> mVertices;
	GLuint mTextureDiffuse, mTextureSpecular;
	std::vector<glm::vec3> mCubePositions;
	std::vector<glm::vec3> mPointLightPositions;
};
