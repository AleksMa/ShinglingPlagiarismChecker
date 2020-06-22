#include <stdio.h>

int main()
{
        long i, a1,  x, a;
        int n;
	scanf ("%d%ld%ld",&n, &x, &a1);
	unsigned long p = a1, p1 = n * a1;

 	for (i = 1; i < (n + 1); i++){
	     scanf ("%ld", &a);
             p=p*x+a;

             if (i < n) 
                p1 = p1 * x + a * (n - i);
    }

	printf ("%ld %ld", p, p1);
}
