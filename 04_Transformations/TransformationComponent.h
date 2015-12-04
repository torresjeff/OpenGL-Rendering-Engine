#pragma once

#include <Common/Common.h>

class TransformationComponent : public DrawableGameComponent
{
public:
	TransformationComponent();
	TransformationComponent(Application& application);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	GLuint VAO, VBO, EBO;
	Texture2D mTextureContainer, mTextureAwesomeFace;
	Shader mShader;
	std::vector<GLuint> mIndices;
	std::vector<GLfloat> mVertices;
};
