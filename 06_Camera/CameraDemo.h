#pragma once

#include <Common/Common.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CameraDemo : public DrawableGameComponent
{
public:
	CameraDemo();
	CameraDemo(Application& application);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
protected:
	GLuint VAO, VBO, EBO;
	GLuint texture1, texture2;
	Shader shader;
	std::vector<GLfloat> mVertices;
	Texture2D mTextureContainer, mTextureAwesomeFace;
	std::vector<glm::vec3> mCubePositions;
	
};