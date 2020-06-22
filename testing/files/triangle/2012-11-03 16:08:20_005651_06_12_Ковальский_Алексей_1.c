#include <stdio.h>
#include <math.h>

int main()
{
  unsigned long long a[320000],b[320000],i,k,j,s,u,x,q,y,q1,q2,c;
  j=0;
  for(i=2; i<320000; i++)
    a[i]=i;
  for (i=2; i<320000; i++)
  {
    if ((a[i]!=0) && (2*i<320000))
    {
      b[j]=a[i];
      j++;
      k=2*i;
      while (k<320000)
      {
        a[k]=0;
        k+=i;
      }
    }
  }

  i=1;
  j=2;
  k=0;
  q1=1;
 
  while (k<3000)
  {
    s=i*j/2;

    if (j%2==0)
      x=j/2;
    else x=j;
    c=0;
    y=sqrt(x);
    q2=1;
    while (b[c]<=y)
    {
      u=0;
      while (x%b[c]==0)
      {
        x/=b[c];
	u++;
      }
      q2*=(u+1);
      c++;
    }
    if (x>1)
      q2*=2;
    k=q1*q2;
    q1=q2;
    i++;
    j++;
  }
    
    
    
    
  printf("%llu\n",s);
  return 0;
}