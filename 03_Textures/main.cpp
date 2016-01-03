#include <Common/Common.h>
#include "TextureApplication.h"
#include <memory>
#include <fstream>
#include "InputHandler.h"

int main()
{
	std::unique_ptr<TextureApplication> textureDemo(new TextureApplication("Textures", 800, 600));

	try
	{
		textureDemo->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
	
}

