#include <stdio.h>

int main ()
{
    int n;
    int x;
    int i;
    int a = 0;
    long long int P1 = 0;
    long long int P2 = 0;
    
    scanf ("%d", &n);
    scanf ("%d", &x);
    
    for (i = 0; i < n; i++) 
    {
        scanf ("%d", &a);
        P1 = (P1 + a)*x;
        if (x != 0)
            P2 = (P2 + a*(n - i))*x;
        else
            P2 = a;
    }
//    printf ("%d %d\n", P1, P2);
    scanf ("%d", &a);
//    printf ("%d", a);
    if (x != 0)
    {
          P1 = P1 + a;
          P2 = P2 / x;
          printf ("%lld %lld\n", P1, P2);
    }
    else
    {
        P1 += a;
        printf ("%lld %lld\n", P1, P2);
    }
    return 0;
}
    