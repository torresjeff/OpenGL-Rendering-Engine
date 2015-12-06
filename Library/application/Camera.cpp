#include "Camera.h"
#include "Application.h"

const float Camera::DefaultFieldOfView = 45.0f;
const float Camera::DefaultNearPlane = 0.01f;
const float Camera::DefaultFarPlane = 100.f;

Camera::Camera(Application& application)
	: GameComponent(application), mFieldOfView(DefaultFieldOfView), mAspectRatio(application.GetAspectRatio()), mNearPlane(DefaultNearPlane), mFarPlane(DefaultFarPlane),
	mPosition(), mDirection(), mRight(), mUp(), mViewMatrix(), mProjectionMatrix()
{}

Camera::Camera(Application& application, float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
	: GameComponent(application), mFieldOfView(fieldOfView), mAspectRatio(aspectRatio), mNearPlane(nearPlane), mFarPlane(farPlane),
	mPosition(), mDirection(), mRight(), mUp(), mViewMatrix(), mProjectionMatrix()
{}

Camera::~Camera()
{
}

void Camera::Initialize()
{
	UpdateProjectionMatrix();
	Reset();
}

void Camera::Update(float DeltaSeconds)
{
	UpdateViewMatrix();
}

void Camera::Reset()
{
	mPosition = glm::vec3(0.0f); // We start at the origin of the world
	mDirection = glm::vec3(0.0f, 0.0f, -1.0f); // We start looking down the -Z axis
	mRight = glm::vec3(1.0f, 0.0f, 0.0f); 
	mUp = glm::vec3(0.0f, 1.0f, 0.0f);

	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix()
{
	glm::vec3 target = mPosition + mDirection;

	mViewMatrix = glm::lookAt(mPosition, target, mUp);
}

void Camera::UpdateProjectionMatrix()
{
	mProjectionMatrix = glm::perspective(mFieldOfView, mAspectRatio, mNearPlane, mFarPlane);
}

void Camera::ApplyRotation(const glm::mat4& transform)
{
	glm::vec4 direction = transform * glm::vec4(mDirection, 0.0f);
	mDirection = (glm::vec3)glm::normalize(direction);

	// Whenever the homogeneous coordinate (w, 4th element of a vec4) is equal to 0 the vector is specifically known as a direction vector since a vector with a w coordinate of 0 cannot be translated.
	glm::vec4 up = transform * glm::vec4(mUp, 0.0f);
	mUp = (glm::vec3)glm::normalize(up);

	mRight = glm::cross(mDirection, mUp);
	mUp = glm::cross(mRight, mDirection);
}

glm::mat4 Camera::GetViewMatrix()
{
	return mViewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return mProjectionMatrix;
}

glm::vec3 Camera::GetPosition() const
{
	return mPosition;
}

void Camera::SetPosition(glm::vec3 position)
{
	mPosition = position;
}

void Camera::SetPosition(float x, float y, float z)
{
	mPosition = glm::vec3(x, y, z);
}

glm::vec3 Camera::GetDirection() const
{
	return mDirection;
}

glm::vec3 Camera::GetRight() const
{
	return mRight;
}

glm::vec3 Camera::GetUp() const
{
	return mUp;
}
