#include <stdio.h>

int main(void)
{
    int k, x0, m;
    scanf("%d %d", &k, &x0);

    m = k+1;

    int a[m], i;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    long long sum;
    sum = a[0];

    for (i = 1; i < m; i++)
        sum = sum*x0 + a[i];

    long long sum1;
    sum1 = a[0]*k;

    for (i = 1; i < m-1; i++)
    {
        sum1 = sum1*x0 + a[i]*(k-1);
        k--;
    }

    printf("%lld %lld ", sum, sum1);

    return 0;
}
