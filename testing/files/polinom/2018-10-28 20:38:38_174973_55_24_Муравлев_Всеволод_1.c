#include <stdio.h>
long long int n,x,a,b,p,pp;
int main()
{
        scanf("%lld %lld", &n, &x);
        long long int m[n+1];
        for(a=0;a<=n;a++){
                scanf("%lld", &b);
                m[a]=b;
        }
        printf("\n");
        p=m[0];
        for(a=1;a<=n;a++){
                p=p*x+m[a];
        }
        pp=m[0]*n;
        for(a=1;a<n;a++){
                pp=pp*x+m[a]*(n-a);
        }
        printf("%lld %lld", p, pp);
}