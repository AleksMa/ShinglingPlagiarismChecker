
#include <stdio.h>
#include <stdlib.h>
 unsigned long long DEL(unsigned long long a)
{
   unsigned long long max=1, k=0, i=0;
   if (a==1 || a==2)
      return a;
   while ((a&1)==0)  {
      k++;
      a>>=1;
   }
   if (a==1)
      return k+1;
   else
      max=k+1;
   for(i=3;i*i<=a;i+=2)  {
      k=0;
      while(a%i==0)  {
         k++;
         a/=i;
      }
      max*=(k+1);
   }
   if (a>1)
      max<<=1;
   return max;
}

int main()
{
    unsigned long long d1=0, d2=0;
    unsigned long long m=0,n=1;
    unsigned long long chislo;
    while (d1*d2<3000)  {
        m++;
        n++;
        if (m%2==0)  {
            d1=DEL(n);
	    d2=DEL(m/2);
	}
	else  {
	    d1=DEL(n/2);
	    d2=DEL(m);
	}
    }
    chislo=(m*(m+1))/2;
    printf("%llu\n",chislo);
    return 0;
}