#include <stdio.h>
#include <math.h>

int main()
{
        long long n, x0, p=0, pp=0, i, k;
        scanf("%lld %lld", &n, &x0);
        for(i=n; i>=0; i--)
        {
                scanf("%lld", &k);
                long long j=1, h=1;
                while (j<i)
                {
                    h*=x0;
                    j++;
                }
                if (i!=0) p+=k*h*x0;
                else p+=k;
                if (i>1) pp+=k*i*h;
                else pp+=k*i;
        }
        printf("%lld %lld", p, pp);
        return 0;
}

