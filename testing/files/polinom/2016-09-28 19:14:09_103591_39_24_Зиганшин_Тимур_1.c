#include <stdio.h>
main()
{
        long n,i;
        long x0,h;
        scanf("%ld\n",&n);
        scanf("%ld\n",&x0);
        h=n;
        long a[n+1];
        for (i=n;i>=0;i=i-1)
                scanf("%ld",&a[i]);
        long y,y1;
        y =a[n];
        while ( n>=1){ 
                y= y*x0 + a[n-1];
                n=n-1;
        }
        n=h;
        y1=a[n]*n;
        while (n>1){
                y1=y1*x0+a[n-1]*(n-1);
                n=n-1;
        }
        printf("%ld %ld\n",y,y1);
        return(1);
}
