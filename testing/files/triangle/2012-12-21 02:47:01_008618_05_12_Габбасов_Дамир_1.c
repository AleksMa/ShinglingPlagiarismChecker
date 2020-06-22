#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pdel(int n)
{
        int k=(int)sqrt(n),i,j,*b=(int*)malloc(k*sizeof(int)),q,p=1,t,*a=(int*)malloc(k*sizeof(int));
	for (i=0;i<k;i++)
		b[i]=i;
	i=0;
	for (j=2;j<k;j++)
		if (b[j]!=-1)
		{
			a[i]=b[j];
			i++;
			for (q=2*j;q<k;q+=j)
				b[q]=-1;
		}
		else
			continue;
	for (j=0;(j<i)&&(n>1);j++)
	{
		t=0;
		while (n%a[j]==0)
		{
			t++;
			n/=a[j];
		}
		p*=(t+1);
	}
	if (n!=1)
		p*=2;
	free(a);
	free(b);
	return p;
}

int kdel(long n)
{
	if (n%2==0)
		return pdel(n/2)*pdel(n+1);
	return pdel(n)*pdel((n+1)/2);
}

int main()
{
	long i,j;
	long k;
	for (i=1;kdel(i)<=3000;i++);
	k=i*(i+1)/2;
	printf("%ld",k);
	return 0;
}