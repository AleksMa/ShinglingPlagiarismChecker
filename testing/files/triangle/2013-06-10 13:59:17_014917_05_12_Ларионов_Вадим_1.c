#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int divisor(long long n)
{
        int count=1;
	long long i, j;
	long long k=sqrt(n);
	char *A = (char*)malloc(k+1);
	
	for (i=0; i<=k; i++)
		A[i]='1';

	for (i=2; i<=k; i++)
	{
		if (A[i]=='1')
		{
			for (j=i*i; j<=k; j+=i)
				A[j]='0';
		}
	}
	
	for (i=2; i<=k; i++)
	{
		if (A[i]=='1' && n%i==0)
		{
			int count1=0;
			for (;n%i==0;)
			{
				n/=i;
				count1++;
			}
			count1++;
			count*=count1;
			if (n==1) break;
		}
	}
	if (n!=1) count*=2; 

	free(A);
	return count;
}


int main()
{
	int d=0;
	long long int a=0, i;

	for (i=10000; d<=3000; i++)
	{
		if (i%2==0) 
			d=divisor(i/2)*divisor(i+1);
		else d=divisor(i)*divisor((i+1)/2);
	}
	i--;
	a=(i+1)*i/2;
	printf("%llu\n",a);

	return 0;
}