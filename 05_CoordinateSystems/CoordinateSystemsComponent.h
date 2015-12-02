#pragma once

#include <Common/Common.h>

class CoordinateSystemsComponent : public DrawableGameComponent
{
public:
	CoordinateSystemsComponent();
	CoordinateSystemsComponent(Application& application);
	
	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
protected:

};
