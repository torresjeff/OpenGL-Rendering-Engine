#pragma once

#include <Common/Common.h>

class LightCastersComponent : public DrawableGameComponent
{
public:
	LightCastersComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderLight;
	GLuint mVAO, mVBO;
	std::vector<GLfloat> mVertices;
	glm::mat4 mLightTransform;
	glm::vec3 mLightPosition;
	GLuint mTextureDiffuse, mTextureSpecular;
	std::vector<glm::vec3> mCubePositions;
};
