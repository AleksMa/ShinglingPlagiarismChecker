#include <stdio.h>

int main()
{
    int N, x, a[358] = {0};
    long sum = 0, k, l;
    scanf("%d %d", &N, &x);
    for(int i = 0; i <= N; i++)
    {
        scanf("%d",&a[i]);
    }
    k = a[0] * x + a[1];
    if (N != 1)
        l = a[0] * x * N + a[1] * (N - 1) ;
    else l = a[0];
    for(int i = 2; i <= N; i++ )
    {
        k = k * x + a[i];
        if  (i != N)
            if (N != 1)
                l = l * x + a[i] * (N - i);
    }
    printf("%ld %ld", k , l);
    return 0;
}
