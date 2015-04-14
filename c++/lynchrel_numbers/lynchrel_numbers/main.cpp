#include <iostream>
#include <vector>
#include <Windows.h>
#include "BigIntegerLibrary.hh"

using std::cout;
using std::endl;
using std::vector;

typedef unsigned int uint;

BigInteger power(int vectorSize)
{
	BigInteger retVal = 1;

	while (vectorSize > 0)
	{
		retVal *= 10;
		--vectorSize;
	}

	return retVal;
}

BigInteger reverseNumber(const BigInteger& number)
{
	vector<BigInteger> numberAsVector;

	BigInteger temp = number;
	while(temp > 0)
	{
		BigInteger temp2 = temp % 10;
		numberAsVector.push_back(temp2);
		temp = temp / 10;
	}

	BigInteger reversedNumber = 0;

	int vectorSize = (int) (numberAsVector.size() - 1);
	size_t i = 0;
	while(vectorSize >= 0)
	{
		reversedNumber += (numberAsVector.at(i) * power(vectorSize));
		--vectorSize;
		++i;
	}

	return reversedNumber;
}

bool isPalindrome(const BigInteger& number)
{
	vector<BigInteger> numberAsVector;
	
	BigInteger temp = number;
	while (temp > 0)
	{
		BigInteger temp2 = temp % 10;
		numberAsVector.push_back(temp2);
		temp = temp / 10;
	}

	size_t start = 0;
	size_t end = numberAsVector.size() - 1;
	const size_t halfSize = numberAsVector.size() / 2;

	while(start < halfSize)
	{
		if (numberAsVector.at(start) != numberAsVector.at(end))
		{
			return false;
		}

		++start;
		--end;
	}

	return true;
}

bool isLynchrel(const BigInteger& number)
{
	const uint maxNumberOfIterations = 50;
	BigInteger temp = number;
	for (uint i = 0; i < maxNumberOfIterations; ++i)
	{
		temp += reverseNumber(temp);
		if (isPalindrome(temp))
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	//isLynchrel(lynchrel);

	int numberOfLynchrels = 0;

	const uint upperRangeLimit = 10000;
	for (uint i = 100; i < upperRangeLimit; ++i)
	{
		if (isLynchrel(i))
		{
			++numberOfLynchrels;
			cout << "Lychrel detected: " << i << endl;
			Sleep(5);
		}
	}

	cout << "Number of Lychrels found in this range: " << numberOfLynchrels << endl;

	return EXIT_SUCCESS;
}