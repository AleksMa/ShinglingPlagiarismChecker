
#include <stdio.h>
int main( )
{
        long long q,w,e,r = 0,t = 0;
        scanf("%lld %lld", &q, &w);
        while ( q>0 )
        {
                scanf("%lld" , &e);
                r = (r + e) * w;
                t = q > 1 ? w*(t+e*q) : t + e;
                --q;
        }
        scanf("%lld",&e);      
        r = r + e;
        printf("%lld %lld", r,t);
 
        return 0;
} 