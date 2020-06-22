#include <stdio.h>
 
int main()
{
    long x, n;
    scanf("%ld", &n);
    scanf("%ld", &x);
    long array[n + 1], c, d;
    
    for(int i = 0; i < (n + 1); i++)
        scanf("%ld", &array[i]);
 
    if (n != 0)
     {
        c = array[0]*x + array[1];
        for(int i = 2; i < (n + 1); i++)
           c = c*x + array[i];
    }
    else
   c = array[0];
 
    for(int i = 0; i < n; i++)
        array[i] = (n - i)*array[i];
 
    if (n == 0)
        d = 0;
    else
        if (n == 1)
           d = array[0];
        else
        {
            d = array[0]*x + array[1];
            for(int i = 2; i < n; i++)
               d = d*x + array[i];
        }
 
    printf("%ld\n", c);
    printf("%ld\n", d);
    return 0;
}