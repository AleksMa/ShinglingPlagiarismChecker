#include <stdio.h>

int main() {
  long n,x0,p;
  scanf("%ld", &n);
  scanf("%ld", &x0);
  scanf("%ld", &p);
  long b[n+1],pp,i,a;
  b[n+1]=pp=p*n;
  for (i=n-1;i>=0;i--){
    scanf("%ld", &a);
    p=p*x0+a;
    b[i]=a*i;
  }
  for (i=n-1; i>=1;i--){
    pp=pp*x0+b[i];
  }
  pp=pp-b[0];
  printf ("%ld %ld",p,pp);
  return 0;
}