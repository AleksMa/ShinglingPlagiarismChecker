#include <stdio.h>



int main()
{
    long long x0,i,a,n,p,p1;

    scanf(" %ld %ld %ld", &n, &x0, &p);
    p1 = p * n;


    for (i=n;i>0;--i) {
        scanf(" %ld", &a);
        p = p * x0 + a;
        if (i > 1) {
            p1 = p1 * x0 + a * (i-1);
        }
    }

    printf("%ld %ld\n",p, p1);

    return 0;
}
