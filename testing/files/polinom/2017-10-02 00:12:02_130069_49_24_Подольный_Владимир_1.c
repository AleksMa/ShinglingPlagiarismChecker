
#include <stdio.h>

int main()
{
        long n, x0, i, Pol, DifPol;
        scanf("%ld %ld", &n, &x0);
        long a[n];
        for (i=0; i<=n; ++i)
                scanf("%ld", &a[i]);
        Pol = a[0];
        for (i=1;i<=n;++i)
                Pol=Pol*x0+a[i];
        DifPol=n*a[0];
        for (i=1;i<=(n-1);++i)
                DifPol=DifPol*x0+(n-i)*a[i];
        printf("%ld %ld", Pol, DifPol);

        return 0;
}
