
#include <stdio.h>

int main()
{
    long int p,m;
    int n,i,x;
    scanf("%d",&n);
    scanf("%d",&x);
    int a[n+1];
    for (i=0; i<n+1; i++){
      scanf("%d",&a[i]);
    }
    p=(a[0]*x+a[1]);
    m=(a[0])*(n);
    for (i=1; i<n; i++){
      p=p*x+a[i+1];
      m=m*x+a[i]*(n-i);
    } 
    printf("%ld %ld\n",p,m);
	return 0;
}
