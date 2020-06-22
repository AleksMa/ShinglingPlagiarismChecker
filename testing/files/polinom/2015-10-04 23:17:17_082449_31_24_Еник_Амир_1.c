
#include <stdio.h>

int main()
{
        long n,x,a,i,P,P1;
        P = 0; P1 = 0;
        scanf ("%ld%ld", &n,&x);

	if (n == 0) 
	{
	 scanf("%ld", &a);
	 P = a; 
	 printf ("%ld %ld\n", P,P1);
	}

	if (n == 1) 
	{
	 scanf("%ld", &a);
	 P = (P+a) * x; P1 = a;
	 scanf("%ld", &a);
	 P = (P+a);
	 printf ("%ld %ld\n", P,P1);
	}
        else if (n != 0)
	     {
	      for (i = n; i >= 2; i--) 
	      {
	        scanf ("%ld", &a);
	        P = (P+a) * x;
	        P1 = (P1+i*a) * x;
	      }

	      scanf ("%ld", &a);
	      P = (P+a) * x; 
	      P1 = (P1+a); 

	      scanf ("%ld", &a);
	      P = (P+a); 

	      printf ("%ld %ld\n", P,P1);
             }  
	return 0;
}
