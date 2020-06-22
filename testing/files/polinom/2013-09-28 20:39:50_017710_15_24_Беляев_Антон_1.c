
#include <stdio.h>

int main()
{
    int n, i = n;
    long int x, a;
    
    scanf ("%d%ld%ld", &n, &x, &a);
    long int p = a, pr = a*n;
    i = n;
    while (i > 0) {
        scanf ("%ld", &a);
        if (i > 1) (pr = ((a*(i - 1)) + pr*x));
        p = p*x + a;
        i--;
    }
    printf ("%ld %ld", p, pr);
    return 0;
}
