
#include <stdio.h>
#include <math.h>
int main(int argc , char ** argv)
{
        signed long n, x, a1, a;
        scanf("%ld%ld%ld%ld", &n, &x, &a, &a1);
        signed long pol = x * a + a1;
        signed long pr = n * x * a + a1 * (n-1);
        n--;
        signed long k=1;
        while (n>0)
        { 
                scanf("%ld", &a);
	        pol = x * pol + a;
	        pr = x * pr + a * (n-1);
	        if (n==2)
	        k=a;
	        n--;
        }
        if (x==0) 
        	printf ("%ld %ld", pol, k);
        else 
        	printf ("%ld %ld", pol, (pr/x)); 
        return 0;
}