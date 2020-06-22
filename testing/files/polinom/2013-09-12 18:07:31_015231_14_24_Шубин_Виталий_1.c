#include <stdio.h>
int main()
{
    long long dif = 0,val = 0,x0,n,i,a;
    scanf("%lld %lld", &n, &x0);
    for(i = n;i >= 0;i--)
    {
        scanf("%lld", &a);
        val = i > 0 ? x0 * (val + a) : val + a;
        if(i > 0)
            dif = i > 1 ? x0 * (dif + a * i) : dif + a;
    }

    printf("%lld %lld", val, dif);

    return 0;
}



