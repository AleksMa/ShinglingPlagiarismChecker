
#include <stdio.h>

main()
{
    long long int i, n, x, s, pr;
    scanf("%lld", &n);
    scanf("%lld", &x);
    long long int a[n+1];
    for (i=0;i<n+1;i++)
        scanf("%lld", &a[i]);
    s=0;
    pr=0;
    for (i=0;i<n+1;i++)
        s=s*x + a[i];
    printf("%lld", s);
    printf("%c",' ');
    for (i=0;i<n;i++)
        pr=pr*x + a[i]*(n-i);
    printf("%lld", pr);
    return 0;
}

