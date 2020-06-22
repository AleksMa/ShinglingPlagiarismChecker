#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int n = 0;
    long int x = 0;
    scanf("%ld", &n);
    long int *k = (long int*)calloc(n + 1, sizeof(long int));
    scanf("%ld", &x);
    int i = 0;
    for (i = 0; i <= n; i++)
    {
        scanf("%ld", &k[i]);
    }
//        for (i = 0; i <= n; i++) printf("%ld", k[i]);


    long int P = 0;
    long int P1 = 0;
    int j = 0;

    for (j = 0; j < n; j++)
    {
        if (j == 0) P = k[j]*x + k[j+1];
        else
        {
            P1 = P*x + k[j+1];
            P = P1;
        }
    }
    int u = 0;
    int m = n;
    long int Polynm = 0;
    long int Polynm1 = 0;
    if (n == 1) Polynm = k[0];
    else
    {
        for (u = 0; u < (n - 1); u++)
        {
        if (u == 0)
            {
                Polynm = k[u]*x*m + k[u+1]*(m - 1);
                m -= 2;
            }
        else
            {
                Polynm1 = Polynm*x + k[u+1]*abs(m);
                Polynm = Polynm1;
                m -= 1;
            }
        }
    }
    free(k);
    printf ("%ld", P);
    printf("\n" "%ld", Polynm);
    return 0;
}