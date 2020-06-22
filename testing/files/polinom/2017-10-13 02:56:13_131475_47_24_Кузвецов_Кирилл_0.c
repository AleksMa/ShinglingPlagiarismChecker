
#include <stdio.h>

int main()
{
            long rez, pr, n, x, a, m;
    int i;
        scanf( "%ld\n%ld\n%ld", &n, &x, &a );
        rez=a;
        pr=a*n;
        m=n;
        for( i=1; i<=n; i++)
            {
            if(m > 1)
            {
                 pr*=x;
            }
            rez*=x;
            scanf( "%ld", &a);
            rez+=a;
            if (m > 1)
            {
                m--;
                pr=pr+a*m;
            }
            }
        printf( "%ld %ld", rez, pr);
	return 0;
}
