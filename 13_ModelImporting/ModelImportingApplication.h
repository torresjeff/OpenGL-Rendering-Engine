#pragma once

#include <Common/Common.h>
#include "ModelImportingComponent.h"


class ModelImportingApplication : public FirstPersonApplication
{
public:
	ModelImportingApplication(std::string name, int width, int height);
	virtual ~ModelImportingApplication();

	virtual void Initialize() override;
private:
	ModelImportingComponent* mLightMapsComponent;
};