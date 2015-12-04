#pragma once

#include <Common/Common.h>

class ShaderComponent : public DrawableGameComponent
{
public:
	ShaderComponent();
	ShaderComponent(Application& application);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	GLuint VAO, VBO;
	std::vector<GLfloat> mVertices;
	Shader mShader;
};
