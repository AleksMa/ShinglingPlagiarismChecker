
#include <stdio.h>

int main()
{        
        long n, x, a1, f, f1, i;
        i=1;
	scanf("%ld%ld%ld", &n, &x, &a1);
	f= a1;
	f1= a1*n;
	if ( n==1 )
	{
		scanf("%ld", &a1);
		f= f*x + a1;
	}
	else
	//1234567890-=>йцукенгшщзхъфывапролджэё]ячсмитьбю/1234567890-qwertyuiop[]asdfghjkl;'\zxcvbnm,./¡™£¢∞§¶•ªº–≠œ∑´®†¥¨ˆøπ“‘åß∂ƒ©˙∆˚¬…æ«Ω≈ç√∫˜µ≤≥÷'//
	{
		for (i=1; i<n; i++)
		{
			scanf("%ld", &a1);
			f = f*x + a1;
			f1 = f1*x + (n-i)*a1;
		}
	}
	if (n >1 )
	{
		scanf("%ld", &a1);
		f = f*x + a1;
	}
	printf("%ld\n%ld\n",f ,f1);
	return 0;
}


