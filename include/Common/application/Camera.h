#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GameComponent.h"
#include "Application.h"

class Camera : public GameComponent
{
public:
	Camera(Application& application);
	Camera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane);
	virtual ~Camera();

	virtual void Initialize() override;
	virtual void Update(float DeltaSeconds) override;

	glm::vec3 GetPosition() const;
	void SetPosition(glm::vec3 position);
	void SetPosition(float x, float y, float z);
	glm::vec3 GetDirection() const;
	glm::vec3 GetRight() const;
	glm::vec3 GetUp() const;

	static const float DefaultFieldOfView;
	static const float DefaultNearPlane;
	static const float DefaultFarPlane;

	virtual void Reset();
	virtual void UpdateViewMatrix();
	virtual void UpdateProjectionMatrix();
	virtual void ApplyRotation(const glm::mat4& transform);
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
protected:
	float mFieldOfView;
	float mAspectRatio;
	float mNearPlane;
	float mFarPlane;

	glm::vec3 mPosition;
	glm::vec3 mDirection;
	glm::vec3 mRight;
	glm::vec3 mUp;

	glm::mat4 mViewMatrix;
	glm::mat4 mProjectionMatrix;
};
