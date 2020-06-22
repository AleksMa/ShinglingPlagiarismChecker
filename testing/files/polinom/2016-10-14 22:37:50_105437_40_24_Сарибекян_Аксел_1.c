#include <stdio.h>

int main ()
{
 int n=0;
 long x;
 scanf("%d",&n);
 scanf("%ld",&x);
 
 
 long p=0;
 long p1=0;
 for( int i=n   ; i>=0  ;  i=i-1 )
 {
  long a;
  scanf("%ld",&a);
  p = p*x + a;
  if (i>0) 
   p1 = p1*x + i*a;
 }
 
 printf("%ld %ld\n",p,p1);
 
 
 
 return 0;
}