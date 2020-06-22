#include <stdio.h>

long long n, a, i, x, pol, pr;
int main()
{
    pol = 0;
    pr = 0;
    scanf("%lli %lli", &n, &x);
    for (i = n; i>=0; i--)
    {
        scanf("%lli", &a);
        if (i == 1)
        {
            pol = (pol + a)* x;
            pr = pr + a;
        }
        else if (n == i)
        {
            pr = a*i*x;
            pol = a*x;
        }
        else if (i == 0)
        {
            pol = pol + a;
        }
        else
        {
            pol = (pol + a) * x;
            pr = (pr + a*i) * x;
        }
    }
    printf("%lli %lli", pol, pr);
    return 0;
}
