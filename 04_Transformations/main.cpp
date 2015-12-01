#include <Common/Common.h>
#include "TransformationDemo.h"
#include <memory>
#include <fstream>
#include "TransformationDemo.h"

int main()
{
	std::unique_ptr<TransformationDemo> textureDemo(new TransformationDemo("Transformations", 800, 600));
	
	try
	{
		textureDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

