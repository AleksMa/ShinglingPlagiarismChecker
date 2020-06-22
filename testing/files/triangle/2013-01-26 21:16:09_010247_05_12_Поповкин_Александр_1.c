#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 1000
#define NN 3000
unsigned long long tri(unsigned long long n)
{
  return n*(n+1)/2;
}
int fact(unsigned long long n, char *a)
{
  char *c=calloc(g, sizeof(char));
  int del=1, i;
  for(i=0;i<g;i++)
  {
    while(a[i]!=0 && n%i==0){
      n/=i;
      c[i]++;
    }
  }
  for(i=0;i<g;i++)
    if(c[i]!=0)
    del*=(c[i]+1);
  free(c);
  return del;
}
int main()
{
    unsigned char *a;
    int i, j, k=28, del=0;
    unsigned long long tre=3;
    a=calloc(30+g,sizeof(unsigned char));
    for(i=0;;i++)
    {
      a[30*i+7]=1;
      if(30*i+7>=g)
        break;
      a[30*i+11]=1;
      a[30*i+13]=1;
      a[30*i+17]=1;
      a[30*i+19]=1;
      a[30*i+23]=1;
      a[30*i+29]=1;
      a[30*i+31]=1;
      if(30*i+31>=g)
	break;
    }
    a[2]=1;
    a[3]=1;
    a[5]=1;
      for(i=0;i<g;i++)
      {
	if(a[i]!=0){
	  for(j=i*i;j<g;j+=i)
	    a[j]=0;
	}
      
      }
	i=1;
    while(del<=NN){
     tre=tri(i);
     if(tre%10!=0)
     {
       i++;
       continue;
     }
     del=fact(tre, a);
     i++;
    }
    free(a);
    printf("%lld\n", tre);
    return 0;
}
