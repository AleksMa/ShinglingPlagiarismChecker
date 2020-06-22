#include <stdio.h>

int main (int argc, char *argv[])
{        
    long int zn = 1, proiz = 1;
	int n = 0,x = 0,i =0;
	scanf("%d", &n);
	scanf("%d", &x);
	int a[n+1];
	for (i = 0; i < n+1; i++)
		scanf("%d", &a[i]);
	zn = a[0]*x+a[1];
	proiz = n*a[0]*x+(n-1)*a[1];
	for (i = 1; i < n; i++){
		zn = zn*x + a[i+1];
	}	 

	if (n != 1){
		for (i = 1; i < n-1; i++){
			proiz = proiz*x +a[i+1]*(n-i-1);
		}}
	else
		proiz = a[0];
	printf("%ld %ld", zn,proiz);
}

