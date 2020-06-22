#include <stdio.h>

int main()
{
    int n, i, j;
    long x;
    long long y, z, t;
    n=x=y=i=t=z=j=0;
    scanf("%d", &n);
    scanf("%ld", &x);
    long mas[n+1];
    for (j=0; j<(n+1); j++)
    {
        scanf("%ld", &t);
        mas[j]=t;
    }
    y=x*mas[0]+mas[1];
    if (n==1) z=mas[0];
    else z=x*n*mas[0]+mas[1]*(n-1);
    for (i=1; i<n; i++)
    {
        y = y * x + mas[i+1];
        if ((n-i-1)>0) z=z*x+(n-1-i)*mas[i+1];
    }
    printf("%ld  %ld", y, z);
    return 0;
}