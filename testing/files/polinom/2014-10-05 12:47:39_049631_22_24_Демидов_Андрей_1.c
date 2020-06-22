#include<stdio.h>

int main()
{
  long p;//polynom
  long pr = 0;
  int i = 0;
  int sv;//svobodnyi chlen
  p = 0;
  int x,n;//x = value of unknown thing, n = stepen'
  int a[100]; //massiv koefficientov
  scanf("%d", &n);
  scanf("%d", &x);
  for(i=0;i < n;++i)
  {
    scanf(" %d\n", &a[i]);
    p=(p+a[i])*x;
    if (i < n-1)
      pr =(pr + (n-i)*a[i])*x;
    else if (i < n )
      pr = pr + a[i]; 
  }
  
  scanf("%ld", &sv);
  
  p=p+sv;
  
  printf("%ld\n", p);
  printf("%ld\n", pr);
   
  return 0;
}