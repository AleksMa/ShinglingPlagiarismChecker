//Полином. Задача 1
#include <stdio.h>

int main(int argc , char ** argv)
{
   long int i, n;
   long int polynom = 0, proizvodnaya = 0, x, a;
   scanf("%ld \n %ld", &n, &x);
   for(i = n; i > 0; i--)
   {
      scanf("%ld", &a);
      polynom = (polynom + a) * x;
      proizvodnaya = (proizvodnaya * x) + (a * i);
   }
   scanf("%ld", &a);
   polynom += a;
   printf("%ld %ld", polynom, proizvodnaya);
   return 0;
}