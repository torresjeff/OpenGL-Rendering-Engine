#pragma once

#include <Common/Common.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CameraComponent : public DrawableGameComponent
{
public:
	CameraComponent(Application& application);
	CameraComponent(Application& application, Camera& camera);

	virtual void Initialize() override;
	virtual void Update(float DeltaSeconds) override;
	virtual void Draw(float DeltaSeconds) override;
	void ConsumeInput(float DeltaSeconds);
protected:
	GLuint VAO, VBO;
	Shader mShader;
	std::vector<GLfloat> mVertices;
	Texture2D mTextureContainer, mTextureAwesomeFace;
	std::vector<glm::vec3> mCubePositions;
	

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // Up vector in world space, used to get the right vector with the cross product
};