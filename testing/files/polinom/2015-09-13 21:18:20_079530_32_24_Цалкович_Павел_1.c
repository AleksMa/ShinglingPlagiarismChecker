
#include <stdio.h>

int main()
{
   long sum =0, P=0, x0, a;
   int n;
   scanf("%d%ld", &n, &x0);
   for(int i = n; i >= 0; i--)
   {
       scanf("%ld", &a);
       sum = sum*x0 + a;
       if (i != 0) P = P*x0 + a*i;
   }
   printf("%ld %ld", sum, P);
       return 0;
}
