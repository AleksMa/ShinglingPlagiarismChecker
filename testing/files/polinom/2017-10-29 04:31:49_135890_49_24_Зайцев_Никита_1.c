#include <stdio.h>

int main(int argc, char **argv)
{
        long n, x, q, a,w=1,e=1,r=0;
	scanf("%ld %ld", &n, &x);
	for (q=n; q>-1 ;--q){
		scanf("%ld" , &a);
		e=(q==n)? e* a:e*x+a;
		r=(q==n)? a*q:(q==0)? r:(r*x)+(a*q);
	}
	printf("%ld %ld ",e,r);
	return 0;
}
