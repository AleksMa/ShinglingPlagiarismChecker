#include <stdio.h>

int main()
{
   int n, i, c;
   long x0, a, s, sp;
   scanf("%d %ld", &n, &x0);
   if (n!=0)
   {
     c=n;
     scanf("%ld", &a);
     s=a;
     sp=c*a;
     c--;
     for (i=1; i!=n+1; i++)
     {
       scanf("%ld", &a);
       s=s*x0+a;
       if (i<n)
         sp=sp*x0+a*c;
       c--;
     }
   } else {
            s=0;
            sp=0;
          }
   printf("%ld %ld", s, sp);
   return 0;
}