#include <iostream>
#include "BigIntegerLibrary.hh"

using std::endl;
using std::cout;

typedef unsigned int uint;

uint getSumOfDigits(BigInteger & n)
{
	uint sumOfDigits = 0;
	while (n > 0)
	{
		BigInteger temp = n % 10;
		uint remainder = temp.toUnsignedInt();
		sumOfDigits += remainder;
		n /= 10;
	}

	return sumOfDigits;
}

int main()
{
	BigInteger nMinus1 = 2;
	BigInteger nMinus2 = 1;
	BigInteger n = 0;
	uint numberOfDoubles = 1;
	for (uint i = 0; i < 100 - 1; ++i)
	{
		if (i % 3 == 0 || i % 3 == 2)
		{
			n = nMinus1 + nMinus2;
		} 
		else
		{
			n = BigInteger(numberOfDoubles) * BigInteger(2) * nMinus1 + nMinus2;
			++numberOfDoubles;
		}

		nMinus2 = nMinus1;
		nMinus1 = n; 
	}

	cout << "Current iteration value: " << getSumOfDigits(n) << endl;
	return EXIT_SUCCESS;
}