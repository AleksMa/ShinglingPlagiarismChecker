#include <stdio.h>

int main(int argc, char **argv)
{
        long n,x0,a,r=0,dr=0,i;
	scanf("%ld %ld",&n,&x0);
	while(n>0)
	{
		scanf("%ld",&a);
		r=r*x0+a;
		dr=dr*x0+a*n--;
	}
	if(n) {printf("The degree of the equation must be nonnegetive\n"); return 0;}
	scanf("%ld",&a);
	r=r*x0+a;
	printf("%ld %ld\n",r,dr);
	return 0;
}
