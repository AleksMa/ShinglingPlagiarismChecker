#include <stdio.h>

int main() {
   long long int n,x,a,value,valuepr;
   scanf("%lli %lli %lli",&n,&x,&a);
   value=a*x;
   valuepr=a*n;
   --n;
   while (n>0) {
      scanf("%lli",&a);
      value=(value+a)*x;
      valuepr=valuepr*x+a*n;
      --n;
   }
   scanf("%lli",&a);
   value=value+a;
   printf("%lli %lli",value,valuepr);
}