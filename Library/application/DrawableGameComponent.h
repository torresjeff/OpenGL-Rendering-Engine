#pragma once

#include "GameComponent.h"

class DrawableGameComponent : public GameComponent
{
public:
	DrawableGameComponent();
	DrawableGameComponent(Application& application);
	virtual ~DrawableGameComponent();

	bool IsVisible() const;
	void SetVisible(bool visible);
	
	virtual void Draw(float DeltaSeconds);
protected:
	bool mVisible;
private:
	DrawableGameComponent(const DrawableGameComponent& rhs);
	DrawableGameComponent& operator=(const DrawableGameComponent& rhs);
	 
};