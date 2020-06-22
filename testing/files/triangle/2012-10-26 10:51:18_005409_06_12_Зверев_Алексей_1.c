#include <stdio.h>
#include <math.h>

#define COUNT 3000
#define SIZE 1000

int triangle(long long d, long *emp);

int main()
{
    long long d = (1ll << 62);
    long emp[SIZE];
    int flag, i, j;

    emp[0] = 1;
    emp[1] = 2;

    for(i = 2; i <= log(d); i++)
    {
        flag = 1;
        for(j = 1; j <= emp[0]; j++)
            if (i % emp[j] == 0) {flag = 0; break;}
        if (flag)
        {
            emp[0]++;
            emp[ emp[0] ] = i;
        }
    }

    d = 0;
    for(i = 1;;i++)
    {
        d += i;
        if ((triangle(d, emp)) >= COUNT) break;
    }

    printf("%lld \n", d);
    return 0;
}

int triangle(long long d, long *emp)
{
    int i, k;
    int max = 1;
    for(i = 1; i <= emp[0]; i++)
    {
        if ((long long)emp[i] * emp[i] > d)  break;
        k = 0;
        if (d % emp[i] == 0)
            do
            {
                d /= emp[i];
                k++;
            }
            while (d % emp[i] == 0);
        if (k) max *= (k+1);

    }
    if (d > 1) max *= 2;
    return max;
}
