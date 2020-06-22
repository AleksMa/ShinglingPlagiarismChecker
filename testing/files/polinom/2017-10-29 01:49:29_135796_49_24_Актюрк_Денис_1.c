#include <stdio.h>

int main () {
  long a = 0, b = 0, c, x, n, i, k;
  scanf("%ld %ld", &n, &x);
  for (int i = n; i > 0; i--) {
    scanf("%ld", &c);
    for( k = i; k > 0; k--) {
      if (x != 0) {
        c *= x;
      }
      else {
        if (i == 1) {
          c *= 1;
        }
        else {
          c *= x;
        }
      }
    }
    if (x != 0) {
      a+= c;
      b += (c / x) * i;
    }
    else {
      if (i == 1) b += c;
        }
  }
  scanf("%ld", &x);
  a += x;
  printf("%ld %ld", a, b);
  return 0;
}
