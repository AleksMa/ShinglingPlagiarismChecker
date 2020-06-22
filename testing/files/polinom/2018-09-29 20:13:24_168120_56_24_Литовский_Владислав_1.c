#include <stdio.h>

int main(int argc, char** argv)
{
        unsigned long n;
	long x0;

	scanf("%lu%ld", &n, &x0);
	long a = 0, a1, b = 0;

	for (unsigned long i = 0; i <= n; i++)
	{
		scanf("%ld", &a1);
		b = b * x0 + a;
		a = a * x0 + a1;
	}

	printf("%ld %ld", a, b);
	return 0;
}