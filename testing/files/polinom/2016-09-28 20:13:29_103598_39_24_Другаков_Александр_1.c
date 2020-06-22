#include <stdio.h>

int main()
{
        int n;
        long long k,x,b;
	scanf("%d\n %lld\n %lld",&n,&x,&k);
	long long p=n*k;
	long long a=k;
	while (n>0) 
	{
		b=a;
		scanf("%lld",&a);
		k=k*x+a;
		--n;
		p=p*x+n*a;
	}
	p=x?p/x:b;
	printf("%lld %lld",k,p);
	return 0;
}