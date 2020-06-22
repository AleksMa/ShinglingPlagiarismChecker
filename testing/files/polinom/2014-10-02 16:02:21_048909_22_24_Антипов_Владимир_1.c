#include <stdio.h>

int main(int argc , char **argv)
{
        int long i,n;
	int long x0;
 	scanf("%ld", &n);
 	scanf("%ld", &x0);

	int long a[n];
  	for(i=1;i<=n+1;i++)
        {
   	        scanf("%ld", &a[i]);
        }

	int long P=a[1];//значение многочлена
  
        for(i=1;i<=n;++i)
        {
    	        P =P*x0 + a[i+1];
        }
	int long r=n;

	int long P1=a[1]*r;//производная
        for(i=1;i<=n-1;++i)
        {
  		P1 =P1*x0+a[i+1]*(r-1);
  		r -= 1;
        }

	printf("%ld %ld", P, P1);
	return 0;
}