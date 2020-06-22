#include <stdio.h> 

int main()
{
        long long int n,x,a;
        long long int res = 0;
        long long int dx = 0;
	scanf("%lli%lli", &n, &x);
	int i;
	for ( i = 0; i <=n; i++)
	{
	        scanf("%lli", &a);
	        dx = res + dx * x  ;
	        res = res * x  + a ;
	}
	printf("%lli %lli\n", res,dx);
	return 0;
}
