#include <Common/Common.h>
#include "CoordinateSystemsApplication.h"
#include <memory>
#include <fstream>
#include "CoordinateSystemsApplication.h"

int main()
{
	std::unique_ptr<CoordinateSystemsApplication> coordinateSystemsDemo(new CoordinateSystemsApplication("Coordinate Systems", 800, 600));
	
	try
	{
		coordinateSystemsDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

