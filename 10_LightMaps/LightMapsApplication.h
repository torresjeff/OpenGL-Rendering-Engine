#pragma once

#include <Common/Common.h>
#include "LightMapsComponent.h"


class LightMapsApplication : public FirstPersonApplication
{
public:
	LightMapsApplication(std::string name, int width, int height);
	virtual ~LightMapsApplication();

	virtual void Initialize() override;
private:
	LightMapsComponent* mLightMapsComponent;
};