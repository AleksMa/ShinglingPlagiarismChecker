#include <stdio.h>
int main()
{
    long n,x,a,i;
    scanf("%ld %ld %ld", &n, &x, &a);
    long polinom=a*x;
    long derivative=n*a*x;
    for(i=1; i<n; i++)
    {
        scanf("%ld",&a);
        polinom=(polinom+a)*x;
        derivative=(derivative+a*(n-i))*x;
    }
    if (x!=0) derivative=derivative/x;
    else derivative=a;
    scanf("%ld",&a);
    printf("%ld %ld",polinom+a,derivative);
    return 0;
}