int main() 
{
   long a, n, x0, res1, res2;
   scanf("%ld", &n);
   scanf("%ld", &x0);
   scanf("%ld", &a);
   res1 = a * x0;
   if (n != 1) res2 = a * n * x0;
      else res2 = a;
   for (long i = (n - 1); i > 0; i--){
      scanf("%ld ", &a);
      res1 = (res1 + a) * x0;
      if (i != 1) res2 = (res2 + a * i) * x0;
         else res2 = res2 + a;
      }
   scanf("%ld ", &a);
   res1 = res1 + a;
   printf("%ld %ld", res1, res2);
return 0;
}