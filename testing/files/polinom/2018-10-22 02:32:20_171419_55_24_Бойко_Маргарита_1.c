#include <stdio.h>



int main()
{   long  int n, x0;
    scanf("%ld %ld", &n, &x0);
    long long int a, ans1 = 0, ans2 = 0;
    for (int i = 0; i <= n; i++)
    {
        scanf("%lld", &a);
        ans1 = (ans1 * x0 + a);
        if (i != n)
            ans2 = ( ans2 * x0  + a *  (n - i) );
       // printf("%d\n", ans2);
    }
  //  scanf("%d", &a);
   //  ans1 = ans1 + a;
    printf("%lld %lld", ans1, ans2);
    return 0;
}
