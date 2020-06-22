#include<stdio.h>

int main(void) {
 long long int n, x, a, result=0, der=0, totaln, i;
 scanf("%lli", &n);
 scanf("%lli", &x);
 totaln = n;
 for (i = 0; i < n; i++)
  { scanf("%lli", &a);
    result += a;
    result *= x;
    if(i != n-1)
          { der += a*totaln;
            der *= x;
          }
    if(i == n-1)
               { der += a;
               }
    totaln--;

   }

 scanf("%lli", &a);
 result += a;
 printf("%lli %lli", result, der);

 return 0;
}