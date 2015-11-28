#include <Common/Common.h>
#include "ShaderDemo.h"
#include <memory>
#include <fstream>

int main()
{
	std::unique_ptr<ShaderDemo> shaderDemo(new ShaderDemo("Shaders", 800, 600));

	try
	{
		shaderDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

