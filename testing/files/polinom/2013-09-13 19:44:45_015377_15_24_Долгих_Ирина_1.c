#include <stdio.h>

int main ()
{
        long int power=0, x0=0, tmp=0;
        long int value=0, result=0;
        int i=0;
        scanf("%ld", &power);
        scanf("%ld", &x0);
        for(i=0; i<power; i++)
        {
             scanf("%ld", &tmp);
	     value=(value+tmp)*x0;
	     if(x0!=0) result=(result+tmp*(power-i))*x0;
	     else if(i==power-1) result=tmp;
        }
        scanf("%ld", &tmp);
        if(x0!=0) printf("\n%ld %ld", value+tmp, result/x0);
        else printf("\n%ld %ld", value+tmp, result);
        return 0;
}