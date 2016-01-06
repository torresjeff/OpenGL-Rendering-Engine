#pragma once

#include "Application.h"
//class Application;

class GameComponent
{
public:
	GameComponent();
	GameComponent(Application& application);
	virtual ~GameComponent();

	Application* GetApplication();
	void SetApplication(Application& application);

	bool Enabled();
	void SetEnabled(bool enabled);

	virtual void Initialize();
	virtual void Update(float DeltaSeconds);
protected:
	Application* mApplication;
	bool mEnabled;
};
