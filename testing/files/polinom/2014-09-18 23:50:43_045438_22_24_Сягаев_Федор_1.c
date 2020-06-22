#include <stdio.h>

int main(int argc, const char * argv[])
{
    long p, p1, x, n, i;
    scanf("%ld", &n);
    scanf("%ld", &x);
    int a[n];
    for (i = n ; i >= 0; --i)
    {
        scanf("%d", &a[i]);
    }
    p1 = 0;
    p = a[n];
    for(i = n ; i  >= 1; -- i)
    {
        p1 = p1 * x + p;
        p = p * x + a[i - 1];
    }
    printf("%ld\n", p);
    printf("%ld\n", p1);
    return 0;
}