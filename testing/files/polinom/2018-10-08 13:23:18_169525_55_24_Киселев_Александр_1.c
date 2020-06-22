#include <stdio.h>

int main() {
    long long n,x0,s;
    scanf ("%lli%lli" , &n,&x0);
    long long a[n];
    s=n;
    long long b[n];
    int i;
     for (i=0; i<n+1; i++)
     scanf ("%lli,%lli" , &a[i],&b[i]);
    
    long long z;
    z =a[0];
    for (i=0; i<n; i++)
        z=z*x0+a[i+1];
    long long y;
    y=a[0]*n;
    for (i=1; (i<=(n-1)); i++)
    {
        y=y*x0+a[i]*(s-1);
        s=s-1;
    }
    printf ("%lli\n %lli\n", z,y);
    
    return 0;
}
