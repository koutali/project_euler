#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;
typedef unsigned int uint;

bool isANumber(float number)
{
	float floored = floorf(number);
	return ((number - floored) == 0);
}

uint getNumberOfDigits(uint number)
{
	uint numberOfDigits = 0;
	while(number > 0)
	{
		number /= 10;
		++numberOfDigits;
	}

	return numberOfDigits;
}

float getNthRoot(uint number, uint nthRoot)
{
	if (nthRoot != 0)
		return pow((double)number, (1/ ((double)nthRoot)));

	return 0.0f;
}

int main()
{
	uint number = 1;
	uint numberOfValidRoots = 0;
	while(true)
	{
		uint numberOfDigits = getNumberOfDigits(number);
		float nthRoot = getNthRoot(number, numberOfDigits);

		if (isANumber(nthRoot))
		{
			++numberOfValidRoots;

			cout << "Valid root detected for " << number << endl;
			cout << "Current number of valid roots: " << numberOfValidRoots << endl << endl;

			Sleep(10);
		}

		++number;
	}

	return EXIT_SUCCESS;
}