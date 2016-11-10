#include "stdafx.h"
#include <iostream>

using namespace std;

void Flipbyte(int inputByte)
{
	int bitNumber = 0; 
	int outputByte = 0;
	int twoInDegree = 128;
	while (bitNumber != 8)
	{
		if ((inputByte != 0) && (inputByte & 1))
		{
			outputByte += twoInDegree; 
		}
		inputByte >>= 1;
		++bitNumber;
		twoInDegree /= 2;
	} 
	cout << outputByte << endl;
}  

int main(int argc, char * argv[]) 
{
	if (argc != 2)
	{
		cout << "Invalid arguments count" << endl <<
			"Usage: flipbyte.exe <input byte>" << endl;
		return 1;
	}
	 
	int inputByte = atoi(argv[1]); 

	if (inputByte < 0 || inputByte > 255)
	{
		cout << "Number entered should be from 0 to 255" << endl;
		return 1;
	}

	Flipbyte(inputByte);

	return 0;
}