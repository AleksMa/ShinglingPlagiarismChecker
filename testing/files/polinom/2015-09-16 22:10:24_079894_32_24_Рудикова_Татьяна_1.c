
#include <stdio.h>

int main()
{
    int n, i;
    long x;
    scanf("%d%ld", &n, &x);
    int a[n + 1];
    for(i = 0; i <= n; i++)
    scanf("%d", &a[i]);
    
    long y, z = a[0] * x;
    for (i = 1;i <= n;i++) {
       y = z + a[i];     
       z = y * x;
    }
    
    long y1, z1 = 0;
    for (i = 0;i < n;i++) {
       y1 = z1 + (n - i) * a[i];     
       z1 = y1 * x;
    }
    printf("%ld %ld\n", y, y1);
  return 0;
}