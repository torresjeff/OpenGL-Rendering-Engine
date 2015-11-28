#pragma once

//#include <Common/application/Application.h>
#include <Common/Common.h>

class ShaderDemo : public Application
{
public:
	ShaderDemo(std::string name, int WIDTH, int HEIGHT);

public:
	virtual void Run() override;
};
