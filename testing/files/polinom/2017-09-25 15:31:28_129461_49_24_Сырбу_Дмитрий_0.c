

#include <stdio.h>

 int main ()
{
 long c,x0,k;
 int n,i,f;
 scanf ("%d", &n );
 scanf ("%ld", &x0 );
 n+=1;
 int a[n];
 for (i = 0; i < n ; i++) scanf ("%d" , &a[i]);
 c=a[0];
 for (i=1;i<n;++i)
 {
 c=c*x0+a[i];
 }
 k=a[0]*(n-1)*x0+a[1]*(n-2);
 f=n-3;
 for (i=2;i<(n-1);++i,--f)
 {
 k=k*x0+f*a[i];
 }
 printf ("%ld " , c);
 printf ("%ld " ,n==2? k/x0:k);
 return 0;
}
