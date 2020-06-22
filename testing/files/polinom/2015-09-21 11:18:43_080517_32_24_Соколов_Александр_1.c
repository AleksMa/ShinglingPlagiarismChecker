#include <stdio.h>


long long int polinom(int n, long x, long a[]);
long long int polinom_(int n_, long x_, long a_[]);

int main()
{
        int n;
	int i=0;
	long x;

	scanf("%d%ld", &n , &x); 	/* Вводим степень полинома и значение х*/

	long a[n+1];

	for (i=0;i<(n+1);++i)
    	    scanf("%ld" , &a[i]);	 /* Вводим коэфицинэты */
	printf("%lld \n", polinom(n,x,a) ); 	/*Выводим полином*/
	printf("%lld \n", polinom_(n,x,a) ); 	/* Выводим производную полиному */

	return 0;
}

long long int polinom(int n, long x, long a[]) 	/* Вычисление полинома по формуле Горнера*/
{ 
	int i=0;
	long long int p=1;
	int j=2;

	p = p*a[0]*x+a[1];
	--n;
	for (i=0,j=2; i<n; ++i,++j)
		p=p*x+a[j];

	return p;
}

long long int polinom_(int n_, long x_, long a_[]) 	/* Вычисление производной полинома по формуле Горнера*/
{
	int i=0;
	long long int p_=1;
	int j=2;
	int c=n_;

	if ( n_ ==1) 
		p_ = a_[0] ;
	else
	{
		p_=p_*a_[0]*n_*x_+(n_-1)*a_[1];
		n_=n_-2;
		for (i=0,j=2;i<(c-2);++i,++j)
		{
			p_=p_*x_+n_*a_[j];
			--n_;
		}
	}

return p_;
}