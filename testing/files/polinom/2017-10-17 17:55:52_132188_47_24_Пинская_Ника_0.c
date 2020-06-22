#include <stdio.h>

int main (int argc, char **argv)
{
        long n, x, a, p, pn, i;
        p=0;
        pn=0;
        scanf("%li\n", &n);
        scanf("%li\n", &x);
        for (i = n; i > 1; i--)
        {
                scanf("%li", &a);
                p += a;
                p *= x;
                pn += a*i;
                pn *= x;
        }
        scanf("%li\a", &a);
        pn +=a;
        p += a;
        p *= x; 
        scanf("%li\a", &a);
        printf("%li %li ", p += a, pn);
        return 0;
}