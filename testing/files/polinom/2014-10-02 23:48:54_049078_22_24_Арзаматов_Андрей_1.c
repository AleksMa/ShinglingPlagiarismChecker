#include <stdio.h>
#include <stdlib.h>
int main()
{
        long long x,y,z;
        int i,n;
        scanf("%d %lld",&n , &x);
        int *a = ( int *)malloc ((n+1) * sizeof ( int ));
        for (i=0;i<=n;i++){
                scanf("%d",&a[i]);
        }
        y=a[0];
        for (i=1;i<=n;i++){
                y=y*x+a[i];
        }
        z=a[0]*n;
        for (i=1;i<n;i++){
                z=z*x+a[i]*(n-i);
        }
        printf("%lld %lld",y,z);
        free (a);
        return 0;
}