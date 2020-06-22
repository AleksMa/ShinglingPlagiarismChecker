#include <stdio.h>

int main()
{
        long long n, x, xn, p, y;
	
	scanf("%lld %lld ", &n, &x);
	long a[n];
	xn=n;
 	
	for (long i=0; i<=n; i++) 
		scanf("%lld", &a[i]);//заполнение массива 
	y=a[0];
	p=a[0]*n;
	
	for (long i=1;i<=n;i++)
		y = y*x + a[i];//считаем функцию
	
	for (long i=1;i<n;i++)
	{
		p = p*x + a[i]*(xn-1);// считаем производную
		xn--;
	}
	printf("%lld %lld", y, p);
	
	return 0;
}
