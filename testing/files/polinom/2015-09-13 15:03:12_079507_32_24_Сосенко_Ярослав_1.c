#include <stdio.h>
int main()
{
    long x = 0;
    long a = 0;
    long n = 0;
    long sum = 0;
    long pro = 0;
    long i = 0;
    long b = 0;
    scanf("%ld", &n);
    scanf("%ld", &x);
    for (i = 0; i < n+1; i++)
    {
        scanf("%ld", &a);
        sum = a + x * sum;
        pro = b * (n - i + 1) + x * pro;
        b = a;
    }

    printf("%ld %ld", sum, pro);
    return 0;
}

