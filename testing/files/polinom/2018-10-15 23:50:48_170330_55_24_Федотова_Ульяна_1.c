#include <stdio.h>
#include <stdlib.h>

int main()
{
        long long a, x,m, res=0, dif=0;
        int i,n;
        scanf ("%d %lld %lld ",&n,&x,&res);
        dif=res*n;
        m=n;
        for (i=0;i<n-1; i++){
                scanf("%lld ", &a);
                res=res*x +a;
                dif=dif*x + a*(m-1);
                m=m-1;
        }
        scanf("%lld",&a);
        res=res*x +a;
        printf("%lld %lld",res,dif);
        return 0;
}
