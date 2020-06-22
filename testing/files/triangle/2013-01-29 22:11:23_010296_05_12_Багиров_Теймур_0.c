#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int  argc, char **argv)
{        
     int  i = 54, n, j, t = 0, z, x = 0, t1 = 0, t2 = 0;
     n = i;
     for ( j = 2; j*j < n; j++)
        	if (n % j == 0 ){
            t1++;
			while (n % j == 0 )
			    n /= j;
		}
     if (n != 1)
        t1++;
     n = i + 1;
     for ( j = 2; j*j < n; j++)
		if (n % j == 0 ){
            t2++;
			while (n % j == 0 )
			    n /= j;
		}
     if (n != 1)
        t2++;
        
     while (t <= 3000){
           t = 0;
           i++;
           t1 = t2;
           t2 = 0;
           for ( j = 2; j*j < n; j++)
		       if (n % j == 0 ){
                  t2++;
			      while (n % j == 0 )
			            n /= j;
               }
            if (n != 1)
               t2++;
           t = t1 * t2 - 1;
     }
     x = (i+1) * i / 2;
     printf("%d\n", x);
     scanf("%d", &x);
     scanf("%d", &x);
     return 0;
}
