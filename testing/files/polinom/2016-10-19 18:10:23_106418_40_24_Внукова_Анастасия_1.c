
#include <stdio.h>

int main()
{
        long a, x, n, i, sum = 0, der = 0;
        scanf ( "%ld%ld", &n, &x );
        for (i = 0; i <= n; i = i + 1)
        {
                scanf ("%ld", &a);
                sum = (sum * x) + a;
                if (i != n) der = (der * x) + (a * (n - i));
        }
        printf("%ld %ld", sum, der);       
	return 0;
}