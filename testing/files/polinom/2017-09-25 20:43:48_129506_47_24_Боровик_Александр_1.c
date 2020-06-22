#include <stdio.h>
long P(long,long,long);

int main()
{
        int n,i;
	scanf("%d", &n);
	n++;
	long array[n],x,res;
	scanf("%ld",&x);
	for(i = 0; i < n; i++)
		scanf("%ld", &array[i]);
	res  = array[0];
	for(i = 0; i < n - 1 ; i++)
		res = P(res,array[i+1],x);
	printf("%ld ", res);

	for(i = 0; i < n; i++)
		array[i] *= (n - i - 1);
	/*for(i = 0; i < n; i++)
		printf("%d ",array[i]);*/
	res  = array[0];
	for(i = 0; i < n - 2 ; i++)
		res = P(res,array[i+1],x);
	printf("%ld ", res);
	return 0;
}


long P(long a1,long a2, long x){
	return (a1*x)+a2;
}
