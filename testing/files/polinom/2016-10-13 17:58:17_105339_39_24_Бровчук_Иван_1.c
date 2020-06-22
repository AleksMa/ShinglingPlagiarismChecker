#include <stdio.h>
int main()
{
    int i, n;
    long x0, result0, result1, a0, a1;
    scanf("%d\n", &n);
    scanf("%ld\n", &x0);
    scanf("%ld\n", &a0);
    result0=a0;
    result1=a0*n;
    for (i=n ; i>=1; --i)
    {
        scanf("%ld", &a1);
        result0=result0*x0+a1;
        if (i>1)
            result1=result1*x0+a1*(i-1);
    }
    printf("%ld %ld\n ", result0, result1);
}
