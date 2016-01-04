#pragma once

#include <Common/Common.h>
#include "MultipleLightsComponent.h"


class MultipleLightsApplication : public FirstPersonApplication
{
public:
	MultipleLightsApplication(std::string name, int width, int height);
	virtual ~MultipleLightsApplication();

	virtual void Initialize() override;
private:
	MultipleLightsComponent* mLightMapsComponent;
};