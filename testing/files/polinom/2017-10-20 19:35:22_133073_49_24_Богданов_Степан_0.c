#include <stdio.h>
#include <string.h>

int main(){
long p,pr,a1,a2,x,n,i;
scanf("%ld",&n);
scanf("%ld",&x);
scanf("%ld",&a1);
p=a1;
pr=a1*n;

for(i=0;i<n;i++){
scanf("%ld",&a2);
p=p*x+a2;
if (i<(n-1))
pr=pr*x+a2*(n-i-1);
}
printf("%ld\n",p);
printf("%ld\n",pr);
return 0;
}
