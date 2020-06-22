
#include <stdio.h>

int main()
{
    int n, x;
    scanf ("%d%d", &n, &x);
    
    long long A[10000];
    for (int i = 0; i < (n + 2); i++)
        scanf ("%lld", &A[i]);
    
    long long P1 = A[0];
    for (int j = 1; j < (n + 1); j++)
        P1 = P1 * x + A[j];
    printf("%lld ", P1);
    
    int k = n;
    long long P2 = A[0] * k;
    for (int j = 1; j < n; j++) {
        P2 = P2 * x + A[j] * (k - 1);
        k--;
    }
    printf("%lld", P2);
    
    return 0;
}