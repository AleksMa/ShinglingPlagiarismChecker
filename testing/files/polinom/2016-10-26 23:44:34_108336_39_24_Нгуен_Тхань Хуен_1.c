
#include <stdio.h>

int main()
{
        int n, i,x0;
        scanf ("%d %d", &n, &x0);
        long a[n+1];
        for (i=0; i< n+1; i++)
        {
                //printf ("a[%d]= ", i);
                scanf ("%ld", &a[i]);
        }
        long P=0,P1=0;
        for (i=0 ; i< n; i++)
        {
                P+=a[i];
                P*=x0;
        }
        P= P + a[n];
        printf ("%ld\n", P);
        for (i=0;i<n-1;i++){
            P1=P1+a[i]*(n-i);
            P1*=x0;
        }
        P1+=a[n-1];
        printf("%ld",P1);
        return 0;
}
