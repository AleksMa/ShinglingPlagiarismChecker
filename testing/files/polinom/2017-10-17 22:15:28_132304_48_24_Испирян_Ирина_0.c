
#include <stdio.h>

int main()
{
    long n,x0,sum,sump,h;
    int i,j;
 
    scanf("%ld %ld \n",&n,&x0);
    long a[n+1];
    for (j=0;j<=n;j++)
      a[j]=0;
    for(i=0;i<=n;i++)
        scanf("%ld ",&a[i]);
        sum=a[0];
    for(i=0;i<n;i++)
        sum=sum*x0+a[i+1];
        sump=a[0]*n;
        h=n-1;
    for (i=0;i<n-1;i++)
    {
        sump=sump*x0+a[i+1]*h;
        h--;
    }
    
    printf("%ld %ld ",sum,sump);
        return 0;
}
