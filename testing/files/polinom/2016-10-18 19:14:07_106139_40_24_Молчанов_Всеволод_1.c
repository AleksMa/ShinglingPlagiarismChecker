
#include <stdio.h>

int main(int argc, char **argv)
{
    long int n, x0;
    scanf("%ld%ld", &n, &x0);
    
    long int a[n+1], i;
    for (i = 0; i < n+1; i++)
        scanf("%ld", &a[i]);
    
    long int P = a[0];
    for (i = 1; i < n+1; i++)
        P = P * x0 + a[i];
    
    long int Pd = a[0] * n;
    for (i = 1; i < n; i++)
        Pd = Pd * x0 + a[i] * (n - i) ;
    
    printf("%ld %ld\n", P, Pd);
    return 0;
}