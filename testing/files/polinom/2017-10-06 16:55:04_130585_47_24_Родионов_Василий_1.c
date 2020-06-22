
#include <stdio.h>

int main()
{
int n;
        scanf ("%d", &n);
        long x0;
        scanf ("%ld", &x0);
        long spis[n+1];
        long poly, poly1;
        for (int i=0; i<n+1; i++)
        {
            long koef;
            scanf ("%ld", &koef);
            spis[i]=koef;
        }
        poly=spis[0];
        for (int i=1; i<n+1; i++)
        {
            poly=poly*x0+spis[i];
        }
        if (n==1) {printf ("%ld ", poly);
                printf ("%ld", spis[0]);}
        else{
        poly1=spis[0]*n;
        for (int i=1; i<n; i++)
        {
            poly1=poly1*x0+(n-i)*spis[i];
        }

        printf ("%ld %ld", poly, poly1);
        }
}
