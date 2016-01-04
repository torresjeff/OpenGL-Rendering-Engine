#include "DrawableGameComponent.h"

DrawableGameComponent::DrawableGameComponent()
	: GameComponent(), mVisible(true), mCamera(nullptr)
{}



DrawableGameComponent::DrawableGameComponent(Application & application)
	: GameComponent(application), mVisible(true), mCamera(nullptr)
{}

DrawableGameComponent::DrawableGameComponent(Application & application, Camera & camera)
	: GameComponent(application), mVisible(true), mCamera(&camera)
{}

DrawableGameComponent::~DrawableGameComponent()
{}

bool DrawableGameComponent::IsVisible() const
{
	return mVisible;
}

void DrawableGameComponent::SetVisible(bool visible)
{
	mVisible = visible;
}

Camera* DrawableGameComponent::GetCamera()
{
	return mCamera;
}

void DrawableGameComponent::SetCamera(Camera* camera)
{
	mCamera = camera;
}

void DrawableGameComponent::Draw(float DeltaSeconds)
{}
