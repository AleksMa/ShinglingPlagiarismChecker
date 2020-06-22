#include<stdio.h>
int main()
{
    int i,n;
    long x,p,P,o;
  
    scanf("%d",&n);
    long k[n+1];

    scanf("%ld",&x);
    for(i=n;i>-1;i--)
    {
    
        scanf("%ld",&k[i]);
    }
    p=k[n]*x+k[n-1];
    for(i=n-2;i>-1;i--)
    {
        o=p*x;
        p=o+k[i];
    }
    printf("%ld\n",p);

    P=n*k[n];
    for(i=n-1;i>0;i--)
    {
        o=P*x;
        P=o+i*k[i];
    }
    printf("%ld",P);

}
