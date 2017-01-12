#include "stdafx.h"
#include "Controller.h"

using namespace std;

int main()
{
	vector<shared_ptr<CBody>> bodies;
	CController controller(bodies, cin, cout);
	controller.Info();
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		controller.HandleCommand();
	}

	controller.PrintAllBodies(bodies, cout);
	controller.FindBodyWithMaxMass(bodies);
	controller.FindBodyWithSmallestWeight(bodies);

	return 0;
}
