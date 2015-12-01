#include <Common/Common.h>
#include "TextureDemo.h"
#include <memory>
#include <fstream>
#include "InputHandler.h"

int main()
{
	std::unique_ptr<TextureDemo> textureDemo(new TextureDemo("Textures", 800, 600));

	try
	{
		textureDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}
