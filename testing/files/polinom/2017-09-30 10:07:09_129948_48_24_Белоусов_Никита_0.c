
#include <stdio.h>

int main()
{long n, x, i;

        scanf("%ld %ld", &n, &x);
	long a[n + 1];
		for (i = 0; i<= n; i++)
                        {
			scanf("%ld", &a[i]);
			}
	long P = a[0], DifP = n*a[0];
	for (i = 1; i <= n; i++)
        {
		P = P*x + a[i];
	}
	for  (i=0;i<(n-1);i++)
        {
		DifP = DifP*x + (n - i - 1)*a[i+1];
	}

printf("%ld %ld\n", P, DifP); 
	return 0;
}
