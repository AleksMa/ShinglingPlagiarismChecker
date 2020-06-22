#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    long n;
    scanf("%ld", &n);
    long x0;
    scanf("%ld", &x0);
    long *P;
    P =(long *)malloc((n + 1) * sizeof(long));
    for(long i = 0; i <= n; i++)
        
    {
        scanf("%ld", &P[i]);
        }
    
    long res_p = P[0];
    for(long i = 1; i <= n; i++)
        
    {
        res_p = res_p*x0 + P[i];
    }
    
    printf("%ld\n", res_p);
    
    long res_deriv = P[0] * n;
    for(long i = 1; i < n; i++)
        
    {
        res_deriv = res_deriv * x0 + P[i] * ( n - i);
    }
    
    printf("%ld\n", res_deriv);
    free(P);
}