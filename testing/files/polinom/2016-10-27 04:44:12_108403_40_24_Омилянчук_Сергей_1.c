#include <stdio.h>


int main()     
{
    long long int power, x,derivative, element , c, polinom;
    scanf("%lld", &power);
    scanf("%lld", &x);
    scanf("%lld", &c);
    derivative= c * power;
    
    while(power>0)
    {
        scanf("%lld", &element);
        c=c*x+element;
        power=power-1;
        if(power!=0)derivative= derivative*x+element*power; 
        else derivative= derivative+element*power;

         
    }
    printf("%lld ", c);
    printf("%lld ", derivative);
    return 0;
}
