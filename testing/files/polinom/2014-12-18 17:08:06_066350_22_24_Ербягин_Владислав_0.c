
#include <stdio.h>
int main(int argc, char **arvg)
{
        int long p,p1,x,i,n=0,h;
	scanf("%ld", &n);
	scanf("%ld", &x);
	int long a[n+1];
	for (i=0; i<=n+1; i++)
		scanf("%ld", &a[i]);
		
	p = 0;
	for(i = 0;i <= n; ++i)
		p = p*x+a[i];
	h = n;
	p1 = a[0]*h;
	for(i = 1;i <= n-1; ++i)
	{
		p1 = p1*x+a[i]*(h-1);
		h -= 1;
	}
	printf("%ld %ld", p , p1);
        return 0;
        
}
