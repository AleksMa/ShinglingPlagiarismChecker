#include <stdio.h>

int main()
{
        int n,i;long x,a,a1;
	long pol,prpol;
	scanf ("%d",&n);
	scanf ("%ld",&x);
	scanf ("%ld",&a);
	pol = a;
	prpol = n*a;
	for (i = 1; i < n; i++)
	{
		scanf("%ld", &a1);
		pol=pol * x + a1;
		prpol=prpol * x + (n - i) * a1;
	}
	scanf("%ld",&a1);
	pol = pol * x + a1;
	printf("%ld\n" ,pol);
	printf("%ld\n",prpol);
	return 0;
}