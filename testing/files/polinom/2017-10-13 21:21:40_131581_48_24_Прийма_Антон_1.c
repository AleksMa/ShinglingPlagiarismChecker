#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long n1,n=0,p=0,x=0,i,sum=0;

    scanf("%ld\n", &n);
    long a[n];
    scanf("%ld\n", &x);

    for (i=0;i<n+1;i++)
    {
    scanf("%ld", &a[i]);
    sum = (sum*x)+a[i];
    }
n1=n;
    for (i=0;i<n1;i++){
       p =  p * x + a[i] * (n--);
    }





    printf("%ld %ld", sum, p);
   return 0;
}
