#include <stdio.h>

int main()
{
        long pr=0, p=0, a=0, n=0,i=0, x=0;
	scanf("%ld", &n);
	scanf("%ld", &x);
	for( i=0; i<=n; i++)
	{
		if (i!=n)
		{
			scanf("%ld", &a);
			p=(p+a)*x;
		}
		else
		{
			scanf("%ld", &a);
			p +=a;
		}
		if (i < n-1)
			pr=(pr+(n-i)*a)*x;
		else if (i < n)
			pr +=a;
	}
	printf("%ld ", p);
	printf("%ld", pr);
	
	return 0;
}