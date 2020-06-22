
#include <stdio.h>

int main()
{
    long long a, i, n, x, s = 0, sp = 0;
    scanf("%lli%lli", &n, &x);
    for (i = 0; i <= n; i++)
    {
        scanf("%lli", &a);
        s = (s * x) + a;
        if (i != n) sp = (sp * x) + a * (n - i);
    }
    printf("%lli %lli", s, sp);
    return 0;
}