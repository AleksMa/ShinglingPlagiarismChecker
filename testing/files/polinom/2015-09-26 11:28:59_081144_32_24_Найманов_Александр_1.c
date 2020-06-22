#include "stdio.h"

int main() {
  
  int i, k, n;
  
  long x0, Pn, Pp;
  
  scanf("%d", &n);
  scanf("%ld", &x0);
  
  long a[n+1];
  
  for(i = 0; i <= n; i++) 
    scanf("%ld", &a[i]);
  
  Pn = a[0];
  Pp = a[0]*n;
  
  for(i = 0; i <= n-1; i++) {
    Pn = Pn*x0 + a[i+1];
}

  k = n-1;
  
  for(i = 1; i <= n-1; i++, k--)
    Pp = Pp*x0 + a[i]*k;

  printf("%ld %ld\n", Pn, Pp);
  
  return 0;
}