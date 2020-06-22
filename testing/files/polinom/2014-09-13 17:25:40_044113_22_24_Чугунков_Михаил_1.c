#include "stdio.h"

int main(int argc, char const *argv[])
{
        int n;
	long x, coefficient, polynomValue = 0, polynomDerivative = 0;
	scanf("%u%li", &n , &x);

	int i;
	for (i = 0; i < n; ++i)
	{
		scanf("%li", &coefficient);
		polynomValue = polynomValue * x + coefficient;
		polynomDerivative = polynomDerivative * x + coefficient * (n - i);
	}

	scanf("%li", &coefficient);
	polynomValue = polynomValue * x + coefficient;

	printf("%li\n%li\n", polynomValue, polynomDerivative);
	return 0;
}