#include <iostream>
#include "BigInteger.hh"

using std::cout;
using std::endl;

typedef unsigned int uint;

BigInteger Factorial(const uint n)
{
	BigInteger factorial = 1;
	for(uint i = 1; i < n + 1; ++i)
	{
		factorial *= i;
	}

	return factorial;
}

bool Combination(const uint n, const uint r, BigInteger& p_combination)
{
	if (r > n)
	{
		return false;
	}

	BigInteger simplifiedProduct = 1;
	for (uint i = n; i > r; --i)
	{
		simplifiedProduct *= i;
	}

	p_combination = simplifiedProduct / Factorial(n-r);
	return true;
}

int main()
{
	BigInteger combination = 0;
	int numberOfExceedingCombinations = 0;

	for (int n = 1; n < 101; ++n)
	{
		for (int r = 1; r < n; ++r)
		{
			bool opOk = Combination(n, r, combination);
			if (opOk)
			{
				if (combination > 1000000)
				{				
					cout << "C(" << n << "," << r << ")" << "exceeds 10^6" << endl;
					++numberOfExceedingCombinations;
				}
			}
		}
	}

	cout << "Number of combinations exceeding 10^6: " << numberOfExceedingCombinations << endl;
	return EXIT_SUCCESS;
}