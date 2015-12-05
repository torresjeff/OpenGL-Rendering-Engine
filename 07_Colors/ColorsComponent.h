#pragma once

#include <Common/Common.h>

class ColorsComponent : public DrawableGameComponent
{
public:
	ColorsComponent(Application& application);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
protected:
	std::vector<GLfloat> mVertices;
	GLuint cubeVao, lampVao, VBO;
	Shader mContainerShader, mLightShader;
	Texture2D mTextureContainer;
};
