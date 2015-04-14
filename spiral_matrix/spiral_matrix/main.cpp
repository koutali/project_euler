#include "stdafx.h"

using std::endl;
using std::cout;

int DIMENSION = 7;

bool isPrime(const int c)
{
	mpz_t mpzDiagonal;
	mpz_init_set_si(mpzDiagonal, c);

	int isPrime = mpz_probab_prime_p(mpzDiagonal, 100);
	return (isPrime != 0);
}

int main()
{
	int noOfPrimes = 3;
	int sideLength = 2;
	int c = 9;
	double ratio = 0.0;

	do
	{
		ratio = static_cast<double>(noOfPrimes) / (2 * sideLength + 1);

		sideLength += 2;
		for(int i = 0; i < 3; i++)
		{
			c += sideLength;
			if(isPrime(c)) 
				noOfPrimes++;
		}

		c+= sideLength;
	}while(ratio > 0.10);

	cout << "Dimension of the matrix: " << sideLength << endl;
	return EXIT_SUCCESS;
}