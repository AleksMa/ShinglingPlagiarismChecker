
#include <stdio.h>
int main()
{
        int i, n;
        long int x0, P, Pr;
        scanf( "%ld%ld", &n, &x0 );
        long int a[n];
        for ( int i = 0; i<=n; i++ )scanf( "%ld", &a[i] );
        P=0;
        for ( i = 0; i<=n; i++ ) P = P*x0+a[i];
        Pr=0;
        for ( i = 0; i<n; i++ ) Pr = Pr*x0+a[i]*( n-i );
        printf( "%ld %ld", P, Pr );        
        return 0;
}