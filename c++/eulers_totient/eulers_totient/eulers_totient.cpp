// eulers_totient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "operations.h"
#include "measurement.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cMeasurement totalTime;
	totalTime.StartProgramRuntimeMeasurement();

	const unsigned int number = 50000;
	std::vector<unsigned int> primeNumbers;
	cCommon::GetPrimes(number, primeNumbers);

	unsigned int multResult = 1;
	for each (unsigned int prime in primeNumbers)
	{
		multResult *= prime;
		if (multResult > 1000000)
		{
			multResult /= prime;
			break;
		}
	}

	totalTime.StopProgramRuntimeMeasurement();
	std::cout << "Result: " << multResult << std::endl;

	return 0;
}
