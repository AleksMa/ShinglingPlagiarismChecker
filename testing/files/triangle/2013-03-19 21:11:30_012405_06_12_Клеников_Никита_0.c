#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long count(unsigned long long a)
{
        unsigned long long i,k;
	k=0;
	for(i=0;i<sqrt(a)+1;i++)
	{
		if(a%i == 0)
			k+=2;
	}
	if(sqrt(a)*sqrt(a) == a)
		k--;
	return k;
}

int main(int argc, char *argv[])
{
   unsigned long long a=0,k=0,t=0,del;
   do
   {
         a++;
         //triangle+=a;     
         if(a%2 == 0)
			k = count(a/2)*count(a+1);
		 else
			k = count((a+1)/2)*count(a);
   }
   while(k<3000);
   t = a*(a+1)/2;
   printf("%lld\n", t);                                                     
   return 0;
}