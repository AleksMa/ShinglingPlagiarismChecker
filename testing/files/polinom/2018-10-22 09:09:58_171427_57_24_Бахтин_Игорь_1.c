#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, c, x, i;
    long long p = 0;
    long long p1 = 0;
    scanf("%d%d%d", &n, &x, &c);
    p = x*c;
    p1 = n*c;
    for (i = 0; i < n; i++){
        scanf("%d", &c);
        if(i != (n - 1)){
            p = (p + c)*x;
        } else{
            p = p + c;
        }
        if(i != (n - 1)){
            p1 = (p1*x + c*(n - i - 1));
        }
        }
    printf("%lli %lli\n", p, p1);
    return 0;
}


