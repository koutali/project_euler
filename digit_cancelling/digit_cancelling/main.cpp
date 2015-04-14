#include <iostream>
// #include <map>
#include <cmath>
#include <string>

typedef unsigned int uint;

uint cancelLastDigit(uint number, uint& canceledNumber)
{
	uint numberToReturn = number / 10;
	canceledNumber = number - numberToReturn * 10;
	return numberToReturn;
}

uint cancelFirstDigit(uint number, uint& canceledNumber)
{
	uint numberToReturn = number % 10;
	canceledNumber = (number - numberToReturn) / 10;
	return numberToReturn;
}

bool matchingFloats(float numberOne, float numberTwo)
{
	const float delta = 0.00001f;

	float difference = abs(numberOne - numberTwo);
	return (difference < delta);
}

bool isDivisibleByEleven(uint number)
{
	return (number % 11) == 0;
}

bool cancelLastDigitOfNumerator(uint numerator, uint denominator)
{
	//if (isDivisibleByEleven(numerator) && isDivisibleByEleven(denominator))
	//{
	//	return false;
	//}

	float divisionResult = (static_cast<float>(numerator)) / denominator;

	uint canceledNumberFromNumerator = 0;
	uint canceledNumberFromDenominator = 0;

	uint numeratorWithoutLastDigit = cancelLastDigit(numerator, canceledNumberFromNumerator);
	uint denominatorWithoutFirstDigit = cancelFirstDigit(denominator, canceledNumberFromDenominator);

	if (canceledNumberFromDenominator != canceledNumberFromNumerator)
	{
		return false;
	}

	if (denominatorWithoutFirstDigit == 0)
	{
		return false;
	}

	float divisionResultWithCancelation = (static_cast<float>(numeratorWithoutLastDigit)) / denominatorWithoutFirstDigit;
	return matchingFloats(divisionResult, divisionResultWithCancelation);
}

int main()
{
	const uint upperLimit = 100;

	for (uint numerator = 10; numerator < upperLimit; ++numerator)
	{
		for (uint denominator = numerator + 10; denominator < upperLimit; ++denominator)
		{
			if (numerator == denominator)
			{
				continue;
			}

			bool match = false;

			match = cancelLastDigitOfNumerator(numerator, denominator);
			if (match)
			{
				std::cout << "numerator: " << numerator << std::endl;
				std::cout << "denominator: " << denominator << std::endl << std::endl; 
			}
		}
	}

	return EXIT_SUCCESS;
}