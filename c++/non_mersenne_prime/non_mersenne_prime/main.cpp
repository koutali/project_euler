#include <iostream>
#include <string>
#include "mpir.h"

using namespace std;

int main()
{
	mpz_t multiplicand;
	mpz_init_set_ui(multiplicand, 28433);

	mpz_t base;
	mpz_init_set_ui(base, 2);

	mpz_t exponent;
	mpz_init_set_ui(exponent, 7830457);

	mpz_t modulus;
	mpz_init_set_str (modulus, "10000000000", 10);
	//mpz_init_set_ui(modulus, 100000000);

	mpz_t result;
	mpz_init(result);

	mpz_powm(result, base, exponent, modulus); // (2 ^ 7830457) % 10000000000
	mpz_mul(result, result, multiplicand); // 28433 x [(2 ^ 7830457) % 10000000000] 
	mpz_add_ui(result, result,1);

	gmp_printf ("%Zd", result);
	return EXIT_SUCCESS;
}