#include <stdio.h>

int main(int argc, char **argv)
{
    int i,n;
    scanf ("%d", &n);
    long x, k, p=0, pr=0;
    scanf ("%ld", &x);
    for (i=0; i<n+1; i++)
    {
        scanf ("%ld", &k);
        if (i==0) 
        {
            p=k;
            pr= n*k;
        }
        else 
        {
            p=(p*x)+k;
            if (i<n) pr=(pr*x)+(n-i)*k;
        }

    }

    printf ("%ld %ld\n", p, pr);
	return 0;
}