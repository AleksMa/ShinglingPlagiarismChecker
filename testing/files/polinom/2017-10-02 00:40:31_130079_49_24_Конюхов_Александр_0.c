#include <stdio.h>

int main()
{

long n, x0, summ, pr, x2,x1,x;
scanf("%ld %ld %ld %ld", &n, &x0,&x1, &x2);
summ=x1*x0+x2;
pr=x1;
for(int i=1; i<n;i++)
{
scanf("%ld", &x);
pr=pr*x0+summ;
summ=summ*x0+x;
}
printf("%ld %ld", summ, pr);
return 0;
}
