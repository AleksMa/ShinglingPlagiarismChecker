#include <stdio.h>
 
typedef long long int BIG;
 
int main()
{
    BIG n = 0;
    BIG x0 = 0;
    BIG *a = NULL;
    BIG i = 0;
 
    scanf("%lld", &n);
    scanf("%lld", &x0);
 
    a = (BIG *)malloc (sizeof(BIG) * (n + 1));
    for (i = n; i >= 0; i--)
    {
        scanf("%lld", a + i);
    }
 
    BIG p = a[n];
    BIG p_der = a[n] * n;
 
    for (i = n - 1; i >= 0; i--)
    {
        p = p * x0 + a[i];
        if (i)
            p_der = p_der * x0 + a[i] * i;
    }
 
    printf("%lld %lld", p, p_der);
    
    free(a);
    
    return 0;
}