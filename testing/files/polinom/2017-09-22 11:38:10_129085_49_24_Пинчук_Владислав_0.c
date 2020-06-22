#include <stdio.h>



int main()
{
    long long x0=0,i=0,a=0,n=0,p=0,p1=0;

    scanf(" %lld %lld %lld", &n, &x0, &p);
    p1 = p * n;


    for (i=n;i>0;--i) {
        scanf(" %lld", &a);
        p = p * x0 + a;
        if (i>1)
        p1 = p1 * x0 + a * (i-1);
    }

    printf("%lld %lld\n",p, p1);

    return 0;
}
