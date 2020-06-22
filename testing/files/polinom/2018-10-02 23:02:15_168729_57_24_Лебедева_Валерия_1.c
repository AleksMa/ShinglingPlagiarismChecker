#include <stdio.h>

int main()
{
  long x, n, f,  ff;
  long a[100]={0};
  scanf("%ld\n", &n);
  scanf("%ld\n", &x);
  for (int i=n+1; i>=1; i--)
    scanf("%ld", &(a[i]));
  f=0;
  for (int j=n+1; j>1; j--)
   f=(f+a[j])*x;
  printf("%ld\n", (f+a[1]));
  ff=0;
  for (int j=n+1; j>2; j--)
   ff=(ff+a[j]*(j-1))*x;
  printf("%ld\n", (ff+a[2]));
   
        return 0;
}
