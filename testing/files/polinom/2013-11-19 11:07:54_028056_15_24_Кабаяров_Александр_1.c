#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
        long long i,n,x0,a,P=0,P2=0;
	scanf("%lld %lld", &n,&x0);
	for(i=n;i>0;i--)
	{
		scanf("%lld", &a);
		P=(P*x0+a);
		P2=(P2*x0+a*i);
	}
	scanf("%lld", &a);
	P=(P*x0+a);
	printf("%lld %lld\n",P,P2);
	return 0;
} 