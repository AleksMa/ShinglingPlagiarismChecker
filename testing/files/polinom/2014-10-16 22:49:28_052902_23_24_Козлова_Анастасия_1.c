
#include <stdio.h>

int main()
{
    long int x,P,Q;
    int i=0, n;
    scanf("%i %li", &n,&x);
    long int a[n+1];
    for (i=n;i>=0;i--) 
        scanf("%li", &a[i]);
    P=a[n];
    for (i=n-1;  i>=0; i--)
        P = P*x+a[i];
    printf ("%li\n",P);
    Q=a[n]*n;
    for (i=n;i>1;i--) 
        Q = Q*x+a[i-1]*(i-1);
    printf("%li",Q);
    return 0;
}  
   