#include <stdio.h>
#include <stdlib.h>

int main() {
    long long a , x , b;
    scanf("%lld %lld", &a ,&x);
    b = a+1;
    int i = 0;
    long long * array = malloc((a+1) * sizeof(long long));
    for (; i < (a+1); i++)
    {
        scanf("%lld", &array[i]);
    }
    long long y0 = 0, y1 = 0;
    for (i = 0; i < (a+1); i++)
    {
        y0 = y0*x + array[i];
    }
    for(i=0; i < a ;i++,b--){
        y1 = y1*x + array[i]*(b-1);
    }
    printf("%lld %lld", y0, y1);
    free(array);
    return 0;
}
