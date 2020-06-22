#include <stdio.h>
#include <stdlib.h>
int main()
{
        long long a,b,c;
        int i,n;
        scanf("%d %lld",&n , &a);
        int *k = ( int *)malloc ((n+1) * sizeof ( int ));
        i=0;
        while(i<=n)
        {
        scanf("%d",&k[i]);
        i++;
        }
        b=k[0];
        i=1;
        while(i<=n)
        {
                b=b*a+k[i];
                i++;
        }
        c=k[0]*n;
        i=1;
        while(i<n)
        {
                c=c*a+k[i]*(n-i);
                i++;
        }
printf("%lld %lld",b,c);
free (k);
return 0;
}