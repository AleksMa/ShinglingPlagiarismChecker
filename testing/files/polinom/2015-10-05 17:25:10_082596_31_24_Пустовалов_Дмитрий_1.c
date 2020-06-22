#include <stdio.h>

int main()
{
        long n, x0, factor, poly, poly_diff;
	scanf(" %ld %ld", &n, &x0);
	
	scanf(" %ld", &factor);
	poly = factor;
	poly_diff = factor * n;
	
	while (n > 0)
	{
		scanf(" %ld", &factor);
		poly = poly * x0 + factor;
		n--;
		if (n > 0) poly_diff = poly_diff * x0 + factor * n;
	}

	printf("%ld %ld\n", poly, poly_diff);
	return 0;
}