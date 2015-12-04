#pragma once

#include <Common/Common.h>

class TextureComponent : public DrawableGameComponent
{
public:
	TextureComponent();
	TextureComponent(Application& application);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	GLuint VAO, VBO, EBO;
	std::vector<GLfloat> mVertices;
	std::vector<GLuint> mIndices;
	Texture2D mTextureContainer, mTextureAwesomeFace;
	Shader mShader;
};