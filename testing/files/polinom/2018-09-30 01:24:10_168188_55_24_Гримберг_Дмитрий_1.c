
#include <stdio.h>

int main()
{
        int n,x;
        scanf("%d%d", &n,&x);
	int a[n+1];
	int b[n+1];
	int i;
	for (i=0;i<=n;i++)
		scanf("%i,%i",&a[i],&b[i]);
	long long f=a[0];
	for (i=0;i<n;i++)
		f=f*x+a[i+1];
	for (i=0;i<=n;i++)
        b[i]=(n-i)*(a[i]);
	long long g=b[0];
	for (i=0;(i<(n-1));i++)
		g=g*x+b[i+1];
	printf("%lli %lli",f,g);
	
}
