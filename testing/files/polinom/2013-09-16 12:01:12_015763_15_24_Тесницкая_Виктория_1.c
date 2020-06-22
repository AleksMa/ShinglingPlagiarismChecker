
#include <stdio.h>

int main(int argc, char **argv)
{
        long x, a, P1, P2;
        int i, n;
       /* printf ("Please, input polynomial`s power 'n' and value of the variable 'x' \n");*/
        scanf ("%d%ld", &n, &x);
        /*printf ("input %d  value of coefficients \n", n + 1 );*/
        scanf ("%ld", &a);
        P1 = a;
        P2 = a * n;
        i = n;
        while ( i > 0 ) {
                scanf ("%ld", &a);
                P1= P1 * x + a;
                if (i > 1) P2 = P2 * x + a * (i - 1);  
                i--;
        };  
        printf ("%ld %ld \n", P1, P2);
	return 0;   
} 
