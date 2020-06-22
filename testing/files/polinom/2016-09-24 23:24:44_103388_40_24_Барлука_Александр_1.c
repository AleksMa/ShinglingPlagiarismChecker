#include <stdio.h>

int main()
{
        long int n, x0, a, pol, der;
	scanf("%ld%ld%ld" , &n , &x0 , &a);
	pol = a, der = a * n;
	for (int i = 1; i < n+1; i++)
	{
		scanf("%ld" , &a);
		pol *= x0;
		pol += a;
		if (i < n)
		{
			der *= x0;
			der += a * (n-i);
		}
	}
	
	printf("%ld %ld\n" , pol , der);
	return 0;
}