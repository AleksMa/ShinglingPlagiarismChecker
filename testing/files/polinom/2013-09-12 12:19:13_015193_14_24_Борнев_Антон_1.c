#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint;
typedef long long int llint;
int main(void)
{
    llint tmp;
    llint x;
    llint n; 

    scanf("%lli",&n);
    scanf("%lli",&x);
    n++;
    llint sum = 0;
    llint fx = 0;
    int i;
    for (i = 0; i<n; i++)
    {
        scanf("%lli",&tmp);
        fx = fx*x+sum;
        sum = (sum*x)+tmp;
    }
    printf("%lli %lli\n",sum,fx);
    return 0;
}