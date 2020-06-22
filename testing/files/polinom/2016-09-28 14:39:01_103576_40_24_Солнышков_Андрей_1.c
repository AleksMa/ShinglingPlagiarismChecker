#include <stdio.h>

int main()
{
    int n;
    long long int x, a, value1, value2;
    scanf("%d", &n);
    scanf("%lli", &x);
    scanf("%lli", &a);
    value1 = a;
    value2 = a * n;
    for (n; n > 0; n--)
    {
        scanf("%lli", &a);
        value1 = value1 * x + a;
        if (n > 1)
        {
            value2 = value2 * x + a * (n - 1);
        }
    }
    printf("%lli %lli", value1, value2);
    return 0;
}