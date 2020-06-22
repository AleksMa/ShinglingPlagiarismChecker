#include <stdio.h>

long GornerScheme(long* a, int k, int x)
{
    long sum=0;
    int i;
    for (i=0; i<k+1; ++i) {
        sum *= x;
        sum +=a[i];
         /*Я ТУПААЯ*/
    }
    return(sum);
}
void Proizvodnaya(long* a, int k)
{
    int i,k2=k;
    for (i=0; i<k+1; ++i){
        a[i]= a[i]*k2--;
    }
}
main()
{
    int n,i,x;
    scanf("%d", &n);
    scanf("%d", &x);
    long a[n+1];
    for(i=0; i<n+1; ++i) scanf("%ld", &a[i]);
    printf("%ld ", GornerScheme(a, n, x));
    Proizvodnaya(a, n);
    printf("%ld ", GornerScheme(a, n-1, x));
    return(0);
}
