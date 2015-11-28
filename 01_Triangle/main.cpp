#include "TriangleDemo.h"
#include <memory>

int main()
{
	std::unique_ptr<TriangleDemo> triangleDemo(new TriangleDemo("Triangle", 800, 600));

	try
	{
		triangleDemo->Run();
	}
	catch (const GameException& exception)
	{
		cout << exception.what() << "\n";
	}

	return 0;
}