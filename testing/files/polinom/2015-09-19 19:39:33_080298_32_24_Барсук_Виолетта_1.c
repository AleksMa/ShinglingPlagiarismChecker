#include <stdio.h>
int main(int argc, char **argv)
{
        unsigned int n;
        scanf ("%u", &n);
        long x0, a, a1;
        scanf ("%ld %ld", &x0, &a);
        a1=a;
        long p=a, p1=0;
        int i;
        for (i=0; i<n; i++){
                scanf ("%ld", &a);
                p1=p1*x0+a1*(n-i);
                p=p*x0+a;
                a1=a;
        }
        printf ("%ld %ld\n", p, p1);
        return 0;
}
