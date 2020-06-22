
#include <stdio.h>

int main()
{
  long x0,Pn,Pp;
  int n,i,j;
  scanf("%d\n", &n);
  scanf("%ld\n", &x0);
  long a[n+1];

  for (i=0; i<=n ; i++) { 
    scanf("%ld", &a[i]); 
  }

  if (n>0) {
    Pn=a[0]*x0+a[1] ;
    for (i=2; i<=n; i++) { 
      Pn=(Pn*x0)+a[i];
    }
  }

  if (n==0) {
    Pn=0;
  }


  if (n==0) {
    Pp=0;
  }

  if (n==1) {
    Pp= a[0];
  }

  j=n;

  if (n>1) {
    Pp=a[0]*j*x0 + a[1]*(j-1);
    j=j-2;
    for (i=2 ; i<n; i++ ) { 
      Pp = Pp*x0 + a[i]*j ;
      j=j-1; 
    } 
  }

  printf("%ld\n", Pn);
  printf("%ld\n", Pp);

return 0;
}
