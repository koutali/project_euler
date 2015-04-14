#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <Windows.h>

using std::endl;
using std::cout;
using std::vector;
using std::reverse;
using std::pow;

typedef unsigned long ulong;
typedef unsigned int uint;

bool isPandigital(const vector<uint>& p_numberAsVector)
{
	if (p_numberAsVector.size() != 9)
	{
		return false;
	}

	for (uint i = 0; i < p_numberAsVector.size(); ++i)
	{
		for (uint j = i + 1; j < p_numberAsVector.size(); ++j)
		{
			if (p_numberAsVector.at(i) == p_numberAsVector.at(j))
			{
				return false;
			}
		}
	}

	return true;
}

void appendNumberToVector(vector<uint>& p_numberAsVector, const uint c_number)
{
	ulong l_numberCopy = c_number;

	while (l_numberCopy > 0)
	{
		uint l_lastDigit = l_numberCopy % 10;
		p_numberAsVector.push_back(l_lastDigit);
		l_numberCopy = l_numberCopy / 10;
	}
}

ulong convertVectorToNumber(const vector<uint>& p_numberAsVector)
{
	ulong l_retNumber = 0;

	int l_vectorSize = (int) (p_numberAsVector.size() - 1);
	for (size_t i = 0; i < p_numberAsVector.size(); ++i)
	{
		l_retNumber += p_numberAsVector.at(i) * (ulong)(pow(10.0f, l_vectorSize));
		--l_vectorSize;
	}

	return l_retNumber;
}

int main()
{
	for (uint l_number = 101; l_number < 10000; ++l_number)
	{
		vector<uint> l_numberAsVector;
		uint l_multiplyBy = 2;
		appendNumberToVector(l_numberAsVector, l_number);

		while(l_numberAsVector.size() < 9)
		{
			uint temp = l_number * l_multiplyBy;
			appendNumberToVector(l_numberAsVector, temp);
			++l_multiplyBy;
		}

		if (isPandigital(l_numberAsVector))
		{
			reverse(l_numberAsVector.begin(), l_numberAsVector.end());
			// convert to number and print it out
			cout << "Number that produced pandigital: " << l_number << endl;
			cout << convertVectorToNumber(l_numberAsVector) << endl << endl;
			Sleep(1000);
		}
	}

	return EXIT_SUCCESS;
}