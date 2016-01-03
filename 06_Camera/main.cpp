#include <Common/Common.h>
#include "CameraApplication.h"
#include <memory>
#include <fstream>
#include "CameraApplication.h"

int main()
{
	std::unique_ptr<CameraApplication> cameraDemo(new CameraApplication("Coordinate Systems", 800, 600));
	
	try
	{
		cameraDemo->Run();
	}
	catch (const GameException& exception)
	{
		std::cerr << exception.what() << "\n";
	}
	
}

