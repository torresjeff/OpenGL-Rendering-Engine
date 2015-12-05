#pragma once

#include <Common/Common.h>
#include "CoordinateSystemsComponent.h"

class CoordinateSystemsApplication : public Application
{
public:
	CoordinateSystemsApplication(std::string name, int width, int height);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;
private:
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f };
	CoordinateSystemsComponent* mCoordinateSystemDemo;
};


