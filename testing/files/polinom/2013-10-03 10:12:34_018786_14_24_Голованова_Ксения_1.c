#include <stdio.h>

int main(void)
{
    long long int n,i,P,Pf,x;
    scanf ("%lli",&n);
    scanf ("%lli",&x);
    long long int N [n + 1];
    for (i = 0; i <= n; ++i)
        scanf ("%lli",&N [i]);
    P = 0;
    Pf = 0;
    for (i = 0; i <= n; ++i) {
        Pf = Pf * x + P;
        P = P * x + N[i];
    }
    printf("%lli ",P);
    printf("%lli ",Pf);
    return 0;
} 