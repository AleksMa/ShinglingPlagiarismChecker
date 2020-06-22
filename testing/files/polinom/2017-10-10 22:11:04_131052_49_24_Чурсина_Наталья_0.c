#include <stdio.h>
long x;
long stepen(long a)
{
    long st=1;
    for (long j=0; j<a; j++)
        st=st*x;
    return st;
}
int main()
{
    long  k, i,poly=0,pr=0 ;
    long l,n;
    scanf("%ld%ld",&n,&x );
    l=n;
    for (i=0; i<=n; i++)
    {
        scanf("%ld",&k);
        poly+=k*stepen(l);
        pr+=k*l*stepen(l-1);
        l--;
    }
    printf("%ld %ld\n",poly,pr);
    
    return 0;
}
