#include "stdafx.h"

typedef unsigned int uint;
typedef unsigned long long ulonglong;

ulonglong pow(ulonglong number)
{
	ulonglong power = number;
	for (uint i = 1; i <= number; ++i)
	{
		power *= i;
	}

	return power;
}

void main()
{
	ulonglong result = 0;
	for (uint i = 1; i <= 1000; ++i)
	{
		ulonglong temp = (ulonglong)i;
		result += pow(temp);
	}

	int lastDigit = 0;

	std::vector<int> last10Digits;

	for (uint i = 0; i < 10; ++i)
	{
		lastDigit = result % 10;
		result = result / 10;
		last10Digits.push_back(lastDigit);
	}

	std::reverse(last10Digits.begin(),last10Digits.end());

	for (uint i = 0; i < last10Digits.size(); ++i)
	{
		std::cout << last10Digits.at(i) << " ";
	}

	std::cout << std::endl;
	//std::cout << last10Digits << std::endl;
}