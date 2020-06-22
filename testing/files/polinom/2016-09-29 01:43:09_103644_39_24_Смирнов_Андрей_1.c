
#include <stdio.h>

long long william_george_horner(long long *a, int n, long long x)
{
    int i;
    long long res=a[0];
    for (i =1; i<n; i++){
        res=res*x+a[i];
    }

 return res;
}

void derivative(long long *a, int n)
{
    int i;//-1 - константа -2 - не надо на 1 умножать
    for (i = 0; i<n-2; i++){
        a[i]*=(long long)(n-i-1);
    }
    //free(&a+(n-1)); // почему так нельзя?
}

int main()
{
    long long xo;
    int i, n;

    scanf("%d %lld", &n, &xo);

    long long polynom[n+1];

    for (i = 0; i<=n; i++){
        scanf("%lld", &polynom[i]);
    }
    printf("%lld ", william_george_horner(&polynom[0], n+1, xo));
    derivative(&polynom, n+1);
    printf("%lld", william_george_horner(&polynom[0], n, xo));

 return 0;
}