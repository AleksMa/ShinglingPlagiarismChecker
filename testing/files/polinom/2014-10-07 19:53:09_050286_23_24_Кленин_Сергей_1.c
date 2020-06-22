
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
        int n, i;
	long x0, P=0, P1=0, t, t1;
	int *a;
	scanf("%d", &n);
	if(n<=0)return 0;
	a=(int*)malloc((n+1)*sizeof(int));
	if(a==NULL)
	{
		printf("Not enough memory\n");
		return -1;
	}
	scanf("%ld", &x0);
	for(i=n; i>=0; i--)
	{
		scanf("%d", a+i);
	}
	P=a[n];
	P1=n*a[n];
	for(i=n; i>0; i--)
	{
		P=P*x0+a[i-1];
		if(i>1)P1=P1*x0+(i-1)*a[i-1];
	}
	printf("%ld\n", P);
	printf("%ld\n", P1);
	free(a);
	return 0;
}