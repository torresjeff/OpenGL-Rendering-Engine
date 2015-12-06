#pragma once

#include "GameComponent.h"

class Camera;

class DrawableGameComponent : public GameComponent
{
public:
	DrawableGameComponent();
	DrawableGameComponent(Application& application);
	DrawableGameComponent(Application& application, Camera& camera);
	virtual ~DrawableGameComponent();

	bool IsVisible() const;
	void SetVisible(bool visible);
	Camera* GetCamera();
	void SetCamera(Camera* camera);
	
	virtual void Draw(float DeltaSeconds);
protected:
	bool mVisible;
	Camera* mCamera;
private:
	DrawableGameComponent(const DrawableGameComponent& rhs);
	DrawableGameComponent& operator=(const DrawableGameComponent& rhs);
	 
};