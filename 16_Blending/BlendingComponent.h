#pragma once

#include <Common/Common.h>
#include <map>

enum type
{
	GRASS, WINDOW
};
struct TextureInfo
{
	unsigned int index;
	type t;
};

class BlendingComponent : public DrawableGameComponent
{
public:
	BlendingComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderLight, mShaderQuad, mShaderInvert;
	GLuint mContainerVAO, mContainerVBO, mQuadVAO, mQuadVBO, mFramebufferColor, mFramebufferDepthStencil;
	std::vector<GLfloat> mCubeVertices, mQuadVertices;
	GLuint mTextureContainerDiffuse, mTextureContainerSpecular, mTextureGrass, mTextureWindow;
	std::vector<glm::vec3> mCubePositions, mGrassPositions, mWindowPositions;
	std::vector<glm::vec3> mPointLightPositions;
};
