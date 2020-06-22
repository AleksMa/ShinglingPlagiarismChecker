#include <stdio.h>

main()

{
  long a,x,n,i, P, R;
  scanf("%ld %ld %ld", &n, &x, &a);
  P=a;
  R=n*a;
  for(i=n; i>0; i--)
  { 
    scanf("%ld", &a);
    P=P*x+a;
    if (i>1) {
         R=R*x+a*(i-1);  
    }
  }
  printf("%ld %ld", P, R);
  return 0;
}