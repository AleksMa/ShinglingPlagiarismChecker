#include <stdio.h>

int main()
{

    long n, i, k, p=0, koef;
    long x, c=0, nul=0;
    scanf("%ld", &n);
    scanf("%ld", &x);
    k=n;

    for (i=0; i<=n; i++)
    {
        scanf("%ld", &koef);
        if(n==1)
        nul=koef;
        p=koef+p*x;
        if(n!=i)
        c=koef*(k--)+c*x;
    }
    printf("%ld\n", p);
    printf("%ld\n", c);

    return 0;
}
