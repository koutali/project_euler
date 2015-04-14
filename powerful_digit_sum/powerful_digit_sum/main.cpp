#include <iostream>
#include "BigIntegerLibrary.hh"

using std::cout;
using std::endl;

void power(const BigInteger& p_a, const BigInteger& p_b, BigInteger& p_out)
{
	BigInteger l_tempB = p_b;
	p_out = p_a;
	while(l_tempB > 0)
	{
		p_out *= p_a;
		--l_tempB;
	}
}

BigInteger calculateSum(const BigInteger& p_input)
{
	BigInteger l_sum = 0;

	BigInteger l_temp = p_input;
	while(l_temp > 0)
	{
		BigInteger l_lastDigit = l_temp % 10;
		l_sum += l_lastDigit;
		l_temp /= 10;
	}

	return l_sum;
}

typedef unsigned int uint;
int main()
{
	BigInteger max = 0;

	for (uint a = 99; a > 0; --a)
	{
		for (uint b = 99; b > 0; --b)
		{
			BigInteger out;
			power(a, b, out);

			BigInteger sum = calculateSum(out);
			if (sum > max)
			{
				max = sum;
			}
		}
	}

	cout << "Maximal sum: " << max << endl;
	return	EXIT_SUCCESS;
}