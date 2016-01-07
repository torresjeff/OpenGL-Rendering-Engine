#pragma once

#include <Common/Common.h>
#include "StencilTestingComponent.h"


class StencilTestingApplication : public FirstPersonApplication
{
public:
	StencilTestingApplication(std::string name, int width, int height);
	virtual ~StencilTestingApplication();

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	StencilTestingComponent* mLightMapsComponent;
};