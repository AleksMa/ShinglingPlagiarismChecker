#include <stdio.h>
#include <stdlib.h>


int main(void)
{
        int n = 0;
	int x = 0;
	scanf("%d %d", &n, &x);
	int k = n;
	n = n +1;
	int * A_n = malloc (sizeof(int) * n);
	int i = 0;
	long long y = 0;
	long long y_1 = 0;
	for(i = 0; i < n;i++)
	{
		scanf("%d", &A_n[i]);
	}
	y = (A_n[0]*x + A_n[1]);
	for(i = 2; i < (n); i++)
	{
		y = y*x + A_n[i];
	}
	y_1 = A_n[0]*k;
	k--;
	for(i = 1; i < (n-1); i++)
	{
		y_1 = y_1*x + A_n[i]*k; 
		k--;
	}
	printf("%lld\n", y);
	printf("%lld \n", y_1);
	free(A_n);
	return 0;
	}