#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void getPrimes(unsigned int primeRange, std::vector<unsigned long> & p_primeNumbers)
{
	std::vector <bool> A;

	for (unsigned int i = 0; i <= primeRange; ++i)
	{
		A.push_back(true);
	}

	float tempRange = static_cast<float>(primeRange);
	unsigned int range = static_cast<unsigned int> (sqrt(tempRange));

	for (unsigned int i = 2; i <= range; ++i)
	{
		if (A.at(i) == true)
		{
			unsigned int multiplier = 0;
			unsigned int j = i * i + multiplier * i;
			for (; j <= primeRange; ++multiplier)
			{
				A.at(j) = false;
				j = i * i + multiplier * i;
			}
		}
	}

	for (size_t i = 2; i < A.size(); ++i)
	{
		if (A.at(i) == true)
		{
			p_primeNumbers.push_back(i);
		}
	}
}

void findPrimeDivisors(const std::vector<unsigned long>& primes, const unsigned long number ,std::vector<unsigned long>& divisors)
{
	for (size_t i = 0; i < primes.size(); ++i)
	{
		if (primes.at(i) >= number / 2)
		{
			break;
		}
		else
		{
			if (number % primes.at(i) == 0)
			{
				divisors.push_back(primes.at(i));
			}
		}
	}
}

bool doVectorsIntersect(const std::vector<unsigned long> & vectorOne, 
						const std::vector<unsigned long> & vectorTwo,
						const std::vector<unsigned long> & vectorThree,
						const std::vector<unsigned long> & vectorFour)
{
	for (size_t i = 0; i < vectorOne.size(); ++i)
	{
		bool found = std::find(vectorTwo.begin(), vectorTwo.end(), vectorOne.at(i)) != vectorTwo.end();
		if (found)
		{
			return true;
		}

		found = std::find(vectorThree.begin(), vectorThree.end(), vectorOne.at(i)) != vectorThree.end();
		if (found)
		{
			return true;
		}


		found = std::find(vectorFour.begin(), vectorFour.end(), vectorOne.at(i)) != vectorFour.end();
		if (found)
		{
			return true;
		}
	}

	return false;
}

char * getTime()
{
	time_t rawtime;
	std::time(&rawtime);
	struct tm * timeinfo = std::localtime(&rawtime);
	return asctime(timeinfo);
}

int main()
{
	std::vector<unsigned long> primeNumbers;
	unsigned int primeRange = 1000;

	std::cout << "Calculating primes... " << std::endl;
	getPrimes(primeRange, primeNumbers);
	std::cout << "Done calculating primes... " << std::endl;

	std::cout << "Started the search at " << getTime() << std::endl;

	unsigned long numberOne = 500;
	while(true)
	{
		std::vector<unsigned long> divisorsOfNumberOne;
		
		findPrimeDivisors(primeNumbers, numberOne, divisorsOfNumberOne);
		if (divisorsOfNumberOne.size() < 4)
		{
			numberOne += 1;
			continue;
		}

		unsigned long numberTwo = numberOne + 1;
		std::vector<unsigned long> divisorsOfNumberTwo;

		findPrimeDivisors(primeNumbers, numberTwo, divisorsOfNumberTwo);
		if (divisorsOfNumberTwo.size() < 4)
		{
			numberOne += 1;
			continue;
		}

		unsigned long numberThree = numberTwo + 1;
		std::vector<unsigned long> divisorsOfNumberThree;

		findPrimeDivisors(primeNumbers, numberThree, divisorsOfNumberThree);
		if (divisorsOfNumberThree.size() < 4)
		{
			numberOne += 1;
			continue;
		}

		unsigned long numberFour = numberThree + 1;
		std::vector<unsigned long> divisorsOfNumberFour;

		findPrimeDivisors(primeNumbers, numberFour, divisorsOfNumberFour);
		if (divisorsOfNumberFour.size() < 4)
		{
			numberOne += 1;
			continue;
		}

		/*bool intersectionFound = doVectorsIntersect(divisorsOfNumberOne, divisorsOfNumberTwo, divisorsOfNumberThree, divisorsOfNumberFour);
		if (intersectionFound)
		{
			numberOne += 1;
			continue;
		}

		intersectionFound = doVectorsIntersect(divisorsOfNumberTwo, divisorsOfNumberOne, divisorsOfNumberThree, divisorsOfNumberFour);
		if (intersectionFound)
		{
			numberOne += 1;
			continue;
		}

		intersectionFound = doVectorsIntersect(divisorsOfNumberThree, divisorsOfNumberOne, divisorsOfNumberTwo, divisorsOfNumberFour);
		if (intersectionFound)
		{
			numberOne += 1;
			continue;
		}

		intersectionFound = doVectorsIntersect(divisorsOfNumberFour, divisorsOfNumberOne, divisorsOfNumberTwo, divisorsOfNumberThree);
		if (intersectionFound)
		{
			numberOne += 1;
			continue;
		}*/

		std::cout << "Finished the search at " << getTime() << std::endl;
		std::cout << "Number one: " << numberOne << std::endl;
		std::cout << "Number two: " << numberTwo << std::endl;
		std::cout << "Number three: " << numberThree << std::endl;
		std::cout << "Number four: " << numberFour << std::endl;
		break;
	}

	return EXIT_SUCCESS;
}