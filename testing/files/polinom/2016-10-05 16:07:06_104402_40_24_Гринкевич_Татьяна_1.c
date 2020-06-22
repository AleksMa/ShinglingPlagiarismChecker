#include <stdio.h>

int main()
{
    long int i;
    long int p = 0;
    long int f = 0;
    long int x;
    long int n;
    long int a;


    scanf("%ld", &n);
    scanf("%ld", &x);
    scanf("%ld", &a);

    f = a * x;
    p = n * a;

    for(i = n - 1; i > 0; i--)
    {
        scanf("%ld", &a);
        f=(f + a) * x;
        p = p * x + i * a;
    }

    scanf("%ld", &a);
    f = f + a;
    printf("%ld %ld", f, p);

    return 0;
}
