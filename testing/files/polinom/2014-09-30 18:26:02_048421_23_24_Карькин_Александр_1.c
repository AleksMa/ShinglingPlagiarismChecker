#include<stdio.h>

int main()
{
  long n, x, p, i;
  scanf("%ld %ld", &n, &x);
  long a[n+1];
  for(i=n;i>=0;--i)
    scanf("%ld", &a[i]);
  p=a[n];
    
  for(i=n-1;i>=0;--i)
    p=p*x+a[i];
    
  printf("%ld ", p);
  
  p=n*a[n];
  
  for(i=n-1;i>0;--i)
    p=p*x+a[i]*i;
    
  printf("%ld\n", p);
    
  return 0;
}