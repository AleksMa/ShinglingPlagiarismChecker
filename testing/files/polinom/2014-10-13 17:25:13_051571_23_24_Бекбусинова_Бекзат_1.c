#include <stdio.h>

int main()
{
        long long x, n, p,q;
        int i;
        x=0;
        n=0;
        p=0;
        q=0;

        scanf("%lld\n", &n);
        int a[n+1];
        scanf("%lld\n", &x);
        for (i=0; i<=n; i++) {
                a[i]=0;
                scanf("%d", &a[i]);
        }
        p=a[0];
        for(i=0;i<n; i++) {
                p=p*x +a[i+1];
        }
        printf("%lld ", p);

        for(i=0;i<n; i++) {
                a[i]=a[i]*(n-i);
        }
        q=a[0];
        for(i=0;i<n-1; i++) {
                q=q*x +a[i+1];
        }
        printf("%lld\n", q);
        return 0;
}

