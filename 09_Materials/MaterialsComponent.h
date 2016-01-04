#pragma once

#include <Common/Common.h>

class MaterialsComponent : public DrawableGameComponent
{
public:
	MaterialsComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderLight;
	GLuint mVAO, mVBO;
	std::vector<GLfloat> mVertices;
	glm::mat4 mContainerTransform, mLightTransform;
	glm::vec3 lightPosition{ 0.0f, 2.0f, 3.0f };
};
