#include "stdafx.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int CompareInputFiles(const string & firstFileName, const string & secondFileName, string & error)
{
	char ch1, ch2;
	int currentLine = 1;
	ifstream firstFile(firstFileName), secondFile(secondFileName);

	if (!firstFile.is_open())
	{
		error = error.append("Failed to open file for reading: ").append(firstFileName);
		return -1;
	} 
	 
	if (!secondFile.is_open())
	{
		error = error.append("Failed to open file for reading: ").append(secondFileName);
		return -1;
	}

	auto ReadInputFiles = [&] {
		firstFile.get(ch1);
		secondFile.get(ch2);
		return firstFile && secondFile;
	};

	while (ReadInputFiles())
	{
		if (ch1 == '\n' && ch2 == '\n')
		{
			++currentLine;
		}

		if (ch1 != ch2)
		{
			return currentLine;
		}
	}

	if (firstFile || secondFile)
	{
		return currentLine;
	}

	return 0;
}

string errorMessage = "";
const int FILES_COMPARE_ERROR = -1;
const int FILES_ARE_EQUAL = 0; 

int main(int argc, char * argv[])
{

	if (argc != 3)
	{ 
		cout << "Invalid arguments count\n"
			<< "Usage: compare.exe <input file> <input file>\n";
		return 1;
	}

	int result = CompareInputFiles(argv[1], argv[2], errorMessage);

	if (result == FILES_COMPARE_ERROR)
	{
		cout << errorMessage << "\n";
		return 1;
	}
	else if (result == FILES_ARE_EQUAL)
	{
		cout << "Files are equal!\n";
	}
	else
	{
		cout << "Files are different on line " << result << "\n";
		return 1;
	}

	return 0;
}

