#include "GameComponent.h"

GameComponent::GameComponent()
	: mApplication(nullptr), mEnabled(true)
{}

GameComponent::GameComponent(Application& application)
	: mApplication(&application), mEnabled(true)
{}

GameComponent::~GameComponent()
{
}

Application* GameComponent::GetApplication()
{
	return mApplication;
}

void GameComponent::SetApplication(Application& application)
{
	mApplication = &application;
}

bool GameComponent::Enabled()
{
	return mEnabled;
}

void GameComponent::SetEnabled(bool enabled)
{
	mEnabled = enabled;
}

void GameComponent::Initialize()
{}

void GameComponent::Update(float DeltaSeconds)
{}
