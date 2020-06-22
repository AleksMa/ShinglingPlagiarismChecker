

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
 k=a[0]*(n-1);
 f=n-2;
 for (i=1;i<(n-1);++i,--f)
 {
 k=k*x0+f*a[i];
 }
 printf ("%ld " , c);
 printf ("%ld " ,k);
 return 0;
}
