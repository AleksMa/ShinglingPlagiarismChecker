#include <stdio.h>

int main()
{
    int i;
    long pol, pro;
    long x, c, n;
    scanf("%ld%ld", &n, &x);
    c = n+1;
    pro = 0;
    long m[c];
    for (i = 0; i < c; i++)
    {
        scanf("%lu", &m[i]);

        if (i > 0){
            pol = pol*x +m[i];
        }
        else{
            pol = m[i];
        }
        if (i < n){
            pro = pro*x + m[i]*(c-i-1);
        }
    }

    printf("%ld %ld", pol, pro);
        return 0;
}
