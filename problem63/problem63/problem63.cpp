// problem63.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef unsigned int uint;

uint FindNumberOfDigits(uint number)
{
	uint numberOfDigits = 0;

	do
	{
		number /= 10;
		++numberOfDigits;

	}while(number >= 0);

	return numberOfDigits;
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint number = 10;

	

	return 0;
}
