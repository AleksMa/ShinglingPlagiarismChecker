#include <stdio.h>

int main() 
{
        long n, x, a=0, p=0, pr=0 ;
	scanf("%ld%ld%ld",&n,&x,&a);
	for (int i=0;i<n;i++)
	{
		p+=a;
		p*=x;
		pr+=a*(n-i);
		if (i<n-1)pr*=x;
		//printf("%ld%ld",p,pr);
		scanf("%ld", &a);
	}
	p+=a;
	printf("%ld %ld\n",p,pr);
	return 0;
}
