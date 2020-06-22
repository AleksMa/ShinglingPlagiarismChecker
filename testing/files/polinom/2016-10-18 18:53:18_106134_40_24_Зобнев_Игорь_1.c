#include <stdio.h>

int main(int argc, char **argv)
{
    long a, x, n, P, Proiz;
        scanf ("%ld %ld %ld", &n, &x, &a);
        P = a;
        Proiz = a * n;
        for (; n>1; --n) {
	    scanf ("%ld", &a);
	    P = P * x + a,
	    Proiz = Proiz*x + a*(n-1);
	    }
        scanf ("%ld", &a);
        P = P * x + a;
	printf ("%ld %ld\n", P, Proiz);
	return 0;
}
