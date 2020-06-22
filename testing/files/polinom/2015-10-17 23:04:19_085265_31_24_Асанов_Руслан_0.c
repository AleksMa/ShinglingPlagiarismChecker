#include <stdio.h>
#include <stdlib.h>


int main(void)
{
        int n = 0, x = 0;
	scanf("%d %d", &n, &x);
	int k = n;
	n = n + 1;
	int * a = malloc (sizeof(int) * n);
	int i = 0;
	long long P = 0;
	long long P_1 = 0;
	for(i = 0; i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	P = (a[0]*x + a[1]);
	for(i = 2; i < (n); i++)
	{
		P = P*x + a[i];
	}
	P_1 = a[0]*k;
	k--;
	for(i = 1; i < (n-1); i++)
	{
	  P_1 = P_1*x + a[i]*k; 
		k--;
	}
	printf("%lld ", P);
	printf("%lld ", P_1);
	free(a);
	return 0;
	}