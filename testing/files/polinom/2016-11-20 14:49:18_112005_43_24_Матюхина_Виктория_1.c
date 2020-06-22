
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long x0;
    scanf("%ld", &x0);

    long a[n+1];
    for(int i = n; i >= 0; i--)
    {
        scanf("%ld", &a[i]);
    }

    long P;
    P = a[n];
    for(int i = n; i > 0; i--)
    {
        P = P * x0 + a[i - 1];
    }

    long P1;
    P1 = a[n] * n;
    for(int i = n; i > 1; i--)
    {
        P1 = P1 * x0 + a[i - 1] * (i - 1);
    }
    printf("%ld %ld\n", P, P1);
	return 0;
}
