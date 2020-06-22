#include <stdio.h>
#include <stdlib.h>
unsigned long long Kolvodelit(unsigned long long chislo)
{
         unsigned long long kolvo=1,k=0,i;
         if(chislo==1)
         {
                      return chislo;
         }
         while((chislo&1)==0)
         {
                             k++;
                             chislo>>=1;
         }
         if(chislo==1)
         {
                      return k++;
         }
         else
         { 
             kolvo=k+1;
         }
         for(i=3;i*i<=chislo;i+=2)
         {
                             k=0;
                             while(chislo%i==0)
                             {
                                          k++;
                                          chislo/=i;
                             }
                             kolvo*=(k+1);
         }
         if(chislo>1)
         {
                     kolvo<<=1;
         }
         return kolvo;
}

int main()
{
    int n=3000;
    unsigned long long n2, n1=1,dop;
    unsigned long long iskchislo, i;
    for(i=2;i>0;i+=2)
    {
                  n2=Kolvodelit(i/2);
                  if(n1*n2>n)
                  {
                             iskchislo=(i-1)*i/2;
                             printf("%lld\n",iskchislo);
                             return 0;
                  }
                  n1=Kolvodelit(i+1);
                  if(n1*n2>n)
                  {
                             iskchislo=(i+1)*i/2;
                             printf("%lld\n",iskchislo);
                             return 0;
                  }
    }
}
