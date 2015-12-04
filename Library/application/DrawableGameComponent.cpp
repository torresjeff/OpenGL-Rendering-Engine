#include "DrawableGameComponent.h"

DrawableGameComponent::DrawableGameComponent()
	: GameComponent(), mVisible(true)
{}

DrawableGameComponent::DrawableGameComponent(Application & application)
	: GameComponent(application), mVisible(true)
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

void DrawableGameComponent::Draw(float DeltaSeconds)
{}
