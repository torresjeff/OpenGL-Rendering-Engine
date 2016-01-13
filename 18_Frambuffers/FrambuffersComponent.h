#pragma once

#include <Common/Common.h>

class FrambuffersComponent : public DrawableGameComponent
{
public:
	FrambuffersComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	Shader mShaderContainer, mShaderQuad, mShaderInvert, mShaderGrayscale, mShaderSharpen, mShaderBlur, mShaderEdgeDetection;
	GLuint mContainerVAO, mContainerVBO, mFBO, mQuadVAO, mQuadVBO, mFramebufferColorTexture, mFramebufferDepthStencil;
	std::vector<GLfloat> mVerticesContainer, mVerticesQuad;
	GLuint mTextureDiffuse, mTextureSpecular;
	std::vector<glm::vec3> mCubePositions;
	std::vector<glm::vec3> mPointLightPositions;
};
