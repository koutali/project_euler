#pragma once

typedef unsigned int uint;

class cDivision
{
public:
	cDivision(uint numerator, uint denominator);
	uint GetDenominator(){ return denominator; }
	uint GetNumerator(){ return numerator; }
	
	bool operator<(const cDivision& d);
	bool operator>(const cDivision& d);
	bool operator<=(const cDivision& d);
	bool operator==(const cDivision& d);


private:
	uint numerator;
	uint denominator;

	uint gcd(uint numerator, uint denominator);
};