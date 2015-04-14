#include "stdafx.h"
#include "Division.h"

cDivision::cDivision(uint numerator, uint denominator)
{
	if (denominator == 0)
	{
		throw std::exception("Denominator cannot be zero!");
	}

	uint commonDivisor = gcd(numerator, denominator);
	if (commonDivisor == 0)
	{
		throw std::exception("Gcd cannot be zero!");
	}

	this->numerator = numerator / commonDivisor;
	this->denominator = denominator / commonDivisor;
}

uint cDivision::gcd(uint num1, uint num2)
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

	uint remainder = 0;
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