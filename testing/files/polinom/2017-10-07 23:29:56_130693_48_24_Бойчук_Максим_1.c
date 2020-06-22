
#include <stdio.h>

int main()
{
        long n, x0, i;

    scanf("%ld", &n);
    scanf("%ld", &x0);


    long arr[n + 1], valueP, valueD;
    for(i = 0; i < (n + 1); i++)
        scanf("%ld", &arr[i]);

    if (n == 0)
        valueP = arr[0];
    else
    {
        valueP = arr[0]*x0 + arr[1];
        for(i = 2; i < (n + 1); i++)
            valueP = valueP*x0 + arr[i];
    }

    for(i = 0; i < n; i++)
        arr[i] = (n - i)*arr[i];

    if (n == 0)
        valueD = 0;
    else
        if (n == 1)
            valueD = arr[0];
        else
        {
            valueD = arr[0]*x0 + arr[1];
            for(i = 2; i < n; i++)
                valueD = valueD*x0 + arr[i];
        }

    printf("%ld\n", valueP);
    printf("%ld\n", valueD);
	return 0;
}
