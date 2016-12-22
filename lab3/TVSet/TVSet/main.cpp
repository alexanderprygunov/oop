#include "stdafx.h"
#include "TVSet.h"
#include "UserCommand.h"

using namespace std;

int main()
{
	CTVSet tvSet;
	CUserCommand userCommand(tvSet);

	string command;
	cout << ">";

	while (getline(cin, command))
	{
		userCommand.RunCommand(command);
		cout << ">";
	}

	return 0;
}