#pragma once

#include <Common/Common.h>
#include "LightCastersComponent.h"


class LightCastersApplication : public FirstPersonApplication
{
public:
	LightCastersApplication(std::string name, int width, int height);
	virtual ~LightCastersApplication();

	virtual void Initialize() override;
private:
	LightCastersComponent* mLightMapsComponent;
};