
#include <stdio.h>

int main()
{
    int n, i, k;
    long x, a, sum, sumpr;
    scanf("%d %ld", &n, &x);
    k=n;
    scanf("%ld", &a);
    sum=a;
    sumpr=k*a;
    k-=1;
    for(i=1;i!=n+1;i++){
        scanf("%ld", &a);
        sum=sum*x+a;
        if (i<n)
            sumpr=sumpr*x+a*k;
            k-=1;
    }
    printf("%ld %ld", sum, sumpr);
    return 0;
}

