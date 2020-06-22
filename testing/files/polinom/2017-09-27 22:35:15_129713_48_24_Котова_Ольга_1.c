#include <stdio.h>
#include <math.h>
int main()
{
        long X, N, P, Pp;
	int i = 0;
	scanf ("%ld", &N);
	scanf ("%ld", &X);
	long A [N + 1];
	for (i = 0; i < (N + 1); i++)
		scanf ("%ld", &A[i]);
	Pp = 0;
	P = A[0];
	for (i = 1; i < (N + 1); i++)
		P = ((P * X) + A[i]);
	for (i = 1; i < (N + 1); i++)
		Pp = ((Pp * X) + (A[i - 1] * (N - i + 1)));
	printf ("%ld %ld\n", P, Pp);
	return 0;
}