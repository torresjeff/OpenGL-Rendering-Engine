#include <Common/Common.h>
#include "CameraDemo.h"
#include <memory>
#include <fstream>
#include "CameraDemo.h"

int main()
{
	std::unique_ptr<CameraDemo> cameraDemo(new CameraDemo("Coordinate Systems", 800, 600));
	
	try
	{
		cameraDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

