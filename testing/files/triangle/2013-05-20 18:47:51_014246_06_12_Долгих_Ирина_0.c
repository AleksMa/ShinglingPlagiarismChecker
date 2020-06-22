#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
        long int n=0;
        int k=0, i=1, l=0;
        while(k!=3000)
        {
             n+=i;
	     if(n%(2*3*5*7*11*13)!=0)
	     {
		  for(l=0; l<sqrt(n)+1; l++)
		  {
		          if(n%l==0) k+=2;
		  }
	     }
        }
        printf("\n%ld\n", n);
        return 0;
}