#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "VectorProcessor.h"
#include <iterator>

using namespace std;

void PrintVector(const vector<double> & numbers)
{
	ostream_iterator<double> output(cout, " ");
	cout << fixed << setprecision(3);
	copy(numbers.begin(), numbers.end(), output);
	cout << endl;
}

int main()
{
	vector <double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	SortVector(numbers);
	PrintVector(numbers);
	cout << endl;
	return 0;
}