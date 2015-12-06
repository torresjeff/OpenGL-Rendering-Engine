#pragma once

#include <Common/Common.h>



class CoordinateSystemsComponent : public DrawableGameComponent
{
public:
	CoordinateSystemsComponent(Application& application);
	CoordinateSystemsComponent(Application& application, Camera& camera);
	
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
protected:
	GLuint VAO, VBO;
	std::vector<GLfloat> mVertices;
	std::vector<glm::vec3> mCubePositions;
	Texture2D mTextureContainer, mTextureAwesomeFace;
	Shader mShader;
};
