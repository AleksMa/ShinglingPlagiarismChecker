
#include <stdio.h>

int main()
{
  int i;
  long x0,p,pdr,n;
  scanf("%ld %ld",&n,&x0);
  long a[n+1];
  for(i=n;i>=0;i--)
    scanf("%ld",&a[i]);
  p=a[n];
  pdr=a[n]*n;
  for(i=n-1;i>=0;i--)
    p=p*x0+a[i];
  for(i=n-1;i>0;i--)
    pdr=pdr*x0+a[i]*i;
  printf("%ld %ld\n",p,pdr);
	return 0;
}
