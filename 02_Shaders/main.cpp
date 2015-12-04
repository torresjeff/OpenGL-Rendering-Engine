#include <Common/Common.h>
#include "ShaderApplication.h"
#include <memory>
#include <fstream>

int main()
{
	std::unique_ptr<ShaderApplication> shaderDemo(new ShaderApplication("Shaders", 800, 600));

	try
	{
		shaderDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

