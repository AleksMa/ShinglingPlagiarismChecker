#include <stdio.h>

int main()
{
    long int x, n, a, P, Pr, i;

    scanf("%ld", &n);
    scanf("%ld", &x);
    scanf("%ld", &a);

    P=a*x;
    Pr=a*n;

    for (i=n-1;i>0;i--)
    {
        scanf("%ld", &a);
        P=(P+a)*x;
        Pr=Pr*x+a*i;
    }

    scanf("%ld", &a);
    P=P+a;
    printf("%ld %ld", P, Pr);
    return 0;
}