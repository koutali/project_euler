#pragma once

class cDivision
{
public:
	cDivision(unsigned int numerator, unsigned int denominator);
	unsigned int GetDenominator(){ return denominator; }
	unsigned int GetNumerator(){ return numerator; }

	bool operator<(const cDivision& d);
	bool operator>(const cDivision& d);
	bool operator<=(const cDivision& d);
	bool operator==(const cDivision& d);


private:
	unsigned int numerator;
	unsigned int denominator;

	unsigned int gcd(unsigned int numerator, unsigned int denominator);
};