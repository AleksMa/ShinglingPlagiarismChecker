
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  unsigned long long s, *a, k, r, e=1000001, n1=1000, n2=1001, c1=0, c2=0, d1=0, d2=0, t1, t2, i, j;
  a=(unsigned long long*)malloc(e*sizeof(unsigned long long));
  for (i=0; i<e; i++)
    a[i]=i;
  for (i=2; i<e; i++) {
    if (a[i]!=0) {
      for (j=i*i; j<e; j+=i) {
        if (a[j]!=0)
	  a[j]=0;
      }
    }
  }
  START:
  if (n1>n2)
    s=sqrt(n1);
  else
    s=sqrt(n2);
  t1=n1;
  t2=n2;
  r=(n1*n2)/2;
  t1/=2;
  for (i=2; i<s; i++) {
    if (a[i]==0)
      continue;
    if (t1%a[i]!=0)
      continue;
    while (t1%a[i]==0) {
      t1/=a[i];
      c1++;
    }
    c1++;
    if (d1==0)
      d1+=c1;
    else
      d1*=c1;
    c1=0;
  }
  if (t1!=1)
    d1*=2;
  for (i=2; i<s; i++) {
    if (a[i]==0)
      continue;
    if (t2%a[i]!=0)
      continue;
    while (t2%a[i]==0) {
      t2/=a[i];
      c2++;
    }
    c2++;
    if (d2==0)
      d2+=c2;
    else
      d2*=c2;
    c2=0;
  }
  if (t2!=1)
    d2*=2;
  if (d1*d2>3000) {
    printf("%llu\n", r);
    free(a);
    return 0;
  }
  else {
    if (n1>n2)
      n2+=2;
    else
      n1+=2;
    c1=0;
    c2=0;
    d1=0;
    d2=0;
    goto START;
  }
}