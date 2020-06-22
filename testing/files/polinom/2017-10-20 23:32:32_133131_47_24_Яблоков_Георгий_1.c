#include <stdio.h>

int main()
{
    long n,x,g,i,p;
    scanf("%ld", &n);
    scanf("%ld", &x);
    long a[n];
    g = 0;
    p = 0;
    
    for (i = n; i > 0; i--)
    {
        scanf("%ld", &a[i]);
        g = (g + a[i])*x;
    }
    
    scanf("%ld", &a[0]);
    
    for (i = n; i > 1; i--)
    {
        p = (p + a[i] * i)*x;
    }
    printf("%ld %ld\n", g + a[0], p+a[1]);
    
    return 0;
}
