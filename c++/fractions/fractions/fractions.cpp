#include "stdafx.h"
#include "fractions.h"

cDivision::cDivision(unsigned int numerator, unsigned int denominator)
{
	if (denominator == 0)
	{
		throw std::exception("Denominator cannot be zero!");
	}

	unsigned int commonDivisor = gcd(numerator, denominator);
	if (commonDivisor == 0)
	{
		throw std::exception("Gcd cannot be zero!");
	}

	this->numerator = numerator / commonDivisor;
	this->denominator = denominator / commonDivisor;
}

unsigned int cDivision::gcd(unsigned int num1, unsigned int num2)
{
	// num 1 must always be greater than num2
	if (num2 > num1)
	{
		std::swap(num1, num2);
	}

	if (num2 == 0)
	{
		throw std::exception("Denominator cannot be zero!");
	}

	unsigned int remainder = 0;
	while (true)
	{
		remainder = num1 % num2;
		if (remainder == 0)
		{
			remainder = num2;
			break;
		}

		num1 = num2;
		num2 = remainder;
	}

	return remainder;
}

bool cDivision::operator<(const cDivision& d)
{
	double result = (double)this->numerator / (double)this->denominator;
	double dResult = (double)d.numerator / (double)d.denominator;
	return ((result - dResult) < 0);
}

bool cDivision::operator>(const cDivision& d)
{
	return !((*this) < d);
}

bool cDivision::operator <= (const cDivision& d)
{
	return (*this) < d || (*this) == d;
}

bool cDivision::operator == (const cDivision& d)
{
	return (this->numerator == d.numerator) && (this->denominator == d.denominator);
}