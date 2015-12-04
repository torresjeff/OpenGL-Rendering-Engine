#include <Common/Common.h>
#include "TransformationApplication.h"
#include <memory>
#include <fstream>
#include "TransformationApplication.h"

int main()
{
	std::unique_ptr<TransformationApplication> textureDemo(new TransformationApplication("Transformations", 800, 600));
	
	try
	{
		textureDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

