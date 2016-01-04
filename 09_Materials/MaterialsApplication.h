#pragma once

#include <Common/Common.h>
#include "MaterialsComponent.h"


class MaterialsApplication : public FirstPersonApplication
{
public:
	MaterialsApplication(std::string name, int width, int height);
	virtual ~MaterialsApplication();

	virtual void Initialize() override;
private:
	MaterialsComponent* mMaterialsComponent;
};