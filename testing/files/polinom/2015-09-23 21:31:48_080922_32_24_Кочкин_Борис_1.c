
#include <stdio.h>

int main()
{
   long n, x0, a, i, res=0, der=0;
   scanf ("%li %li", &n, &x0);
   for (i=n; i>0; i--)
   {
      scanf("%li", &a);
      res=(res+a)*x0;
      if (i>1)
         der=(der+(i*a))*x0;
      else 
         der=der+a;
   }
   scanf("%li", &a);
   res=res+a;
   printf("%li %li\n", res, der);
   return 0;
}