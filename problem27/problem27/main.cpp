#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::ofstream;

void getPrimes(const int primeRange, vector<int> & p_primeNumbers)
{
	vector <bool> A;

	for (int i = 0; i <= primeRange; ++i)
	{
		A.push_back(true);
	}

	float tempRange = static_cast<float>(primeRange);
	int range = static_cast<int> (sqrt(tempRange));

	for (int i = 2; i <= range; ++i)
	{
		if (A.at(i) == true)
		{
			int multiplier = 0;
			int j = i * i + multiplier * i;
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

int main()
{
	const int upperLimit = 1000;

	vector<int> possibleBValues;
	getPrimes(upperLimit, possibleBValues);

	vector<int> primes;
	getPrimes(100000, primes);

	ofstream file("out.txt", std::ios::out);
	if (!file)
	{
		cout << "File could not be opened" << endl;
		return EXIT_FAILURE;
	}

	for (int i = -1000; i < upperLimit; ++i)
	{
		int a = i;

		for (size_t j = 0; j < possibleBValues.size(); ++j)
		{
			int b = possibleBValues.at(j);
			
			int n = 0;
			int numberOfProducedPrimes = 0;

			while(true)
			{
				int primeCandidate = n * n + a * n + b;

				if (find(primes.begin(), primes.end(), primeCandidate) == primes.end())
				{
					if (numberOfProducedPrimes > 50)
					{
						file << "a: " << a << endl;
						file << "b: " << b << endl;
						file << "number of produced primes: " << numberOfProducedPrimes << endl;
						file << endl;
					}

					numberOfProducedPrimes = 0;
					break;
				} 
				
				++n;
				++numberOfProducedPrimes;
			}
		}
	}

	return EXIT_SUCCESS;
}