#pragma once

#include <Common/Common.h>
#include "TextureComponent.h"

class TextureApplication : public Application
{
public:
	TextureApplication(std::string name, int width, int height);

	virtual void Initialize() override;
	virtual void Draw(float DeltaSeconds) override;	
private:
	TextureComponent* mTextureComponent;
	std::vector<GLfloat> mBackgroundColor{ 0.2f, 0.3f, 0.3f, 1.0f }; //Background color
};


