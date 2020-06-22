#include <stdio.h>
int main(int argc, char ***argvc)
{   
        int n,i; 	/*n-степень полинома*/
	long int x,P,P1;	/*Р-значение полинома при х; Р1-значение производной при х*/
	scanf("%d\n%ld\n", &n, &x);
	long int a[n];	/*массив из коэффициентов полинома*/
	for (i=n; i>=0; --i)
		scanf("%ld", &a[i]);
	P=a[n];
	P1=a[n]*n;
	for (i=n; i>0; --i) {
		P=P*x+a[i-1];
		if (i>1) 
			P1=P1*x+a[i-1]*(i-1);
	}
	printf("%ld %ld\n",P,P1);   
	return 0;
}