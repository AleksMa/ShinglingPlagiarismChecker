#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;
int64 calculateF(unsigned int length, const int64 a[], const int64 x0)
{    
    unsigned int i;
    unsigned int n = length - 1;

    int64 result = a[0];
    for (i=1; i <= n; ++i)
    {
        result *= x0;
        result += a[i];
    }
    return result;
}

int64 calculateF_(unsigned int length, const int64 a[], const int64 x0)
{
    unsigned int n = length - 1;
    unsigned int i;
    int k = n;

    int64 result = a[0]*k;

    for (i=1; i < n; ++i)
    {        
        --k;
        result *= x0;
        result += a[i]*k;
    }

    return result;
}

int main(void)
{
    int64 x;
    unsigned int n;
    unsigned int i;

    scanf("%u", &n);
    scanf("%lli", &x);

    int64* a = (int64*)calloc(n + 1, sizeof(int64));


    for (i=0; i<=n; ++i)
    {
        scanf("%lli", &a[i]);
    }

    printf("%lli %lli", calculateF(n+1, a, x), calculateF_(n+1, a, x));

    free(a);
    return 0;
}
