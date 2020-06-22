  #include <stdio.h>
  int main()
  {
    long i, a, x, n;
    scanf("%ld %ld %ld", &n,&x,&a);
    long sum = a, sum1 = a * n;
    for (i = 1; i <= n; i++) {
      scanf("%ld", &a);
      if (i < n) sum1 = sum1 * x + a * (n - i);
      sum = sum * x + a;
    }
    printf("%ld %ld\n", sum,sum1);
    return 0;
  }