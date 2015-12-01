#include <Common/Common.h>
#include "CoordinateSystemsDemo.h"
#include <memory>
#include <fstream>
#include "CoordinateSystemsDemo.h"

int main()
{
	std::unique_ptr<CoordinateSystemsDemo> coordinateSystemsDemo(new CoordinateSystemsDemo("Coordinate Systems", 800, 600));
	
	try
	{
		coordinateSystemsDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}
	
}

