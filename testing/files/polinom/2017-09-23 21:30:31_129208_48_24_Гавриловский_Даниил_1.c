#include <stdio.h>

long polynom(long a[], int size, long x);

int main()
{

    int n;
    scanf("%d", &n);
    long x, a[n + 1];

    scanf("%ld", &x);

    for (int i = 0; i < n + 1; i++)
        scanf("%ld", &a[i]);

    printf("%ld ", polynom(a, n + 1, x));

    for (int i = 0; i < n + 1; i++)
        a[i] *= (n - i);

    printf("%ld", polynom(a, n, x));

        return 0;
}

long polynom(long a[], int size, long x)
{
    if (size == 0)
        return 0; //Если окажется, что берем производную от константы;
    long answ = a[0];
    for (int i = 1; i < size; i++)
        answ = answ * x + a[i];

    return answ;
}
