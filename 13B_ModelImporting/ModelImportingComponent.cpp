#include "ModelImportingComponent.h"

ModelImportingComponent::ModelImportingComponent(Application& application, Camera& camera)
	: DrawableGameComponent(application, camera)
{}

void ModelImportingComponent::Initialize()
{
	mShader = Shader("shaders/model.vert", "shaders/model.frag");
	mModel = Model("res/nanosuit.obj");
}

void ModelImportingComponent::Draw(float DeltaSeconds)
{
	mShader.UseProgram();
	
	glUniformMatrix4fv(glGetUniformLocation(mShader.Program(), "projection"), 1, GL_FALSE, glm::value_ptr(mCamera->GetProjectionMatrix()));
	glUniformMatrix4fv(glGetUniformLocation(mShader.Program(), "view"), 1, GL_FALSE, glm::value_ptr(mCamera->GetViewMatrix()));

	// Draw the loaded model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
	glUniformMatrix4fv(glGetUniformLocation(mShader.Program(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	mModel.Draw(mShader);
}
