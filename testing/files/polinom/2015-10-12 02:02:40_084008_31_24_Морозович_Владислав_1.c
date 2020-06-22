#include <stdio.h>
#include <stdlib.h>
long gorner (int n, long x0, long *a);

int main () {
long *a;
long *ap;
long x0;
int n, i;

scanf ("%d", &n);
scanf ("%ld", &x0);
a=(long *) malloc ((n+1)*sizeof(long));
ap=(long *) malloc ((n)*sizeof(long));
if ((a == NULL)||(ap == NULL)) {
  printf ("not enough memory\n");
  return 1;
  }
for (i=n; i>=0; i--) {
  scanf ("%ld", &a[i]);
  }
for (i=0; i<n; i++) {
  ap[i]=a[i+1]*(i+1);
  }
printf ("%ld ", gorner (n,x0,a));
printf ("%ld\n", (n==0)?0:gorner (n-1,x0,ap));
free (a);
free (ap);
return 0;
}

long gorner (int n, long x0, long *a) {
long val;
int i;
val=0;
for (i=n; i>=0; i--)
  val=val*x0+a[i];
return (val);
}