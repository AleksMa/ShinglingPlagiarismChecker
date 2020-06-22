#include <stdio.h>

int main(){
    int i, usern;
    long x0, p, dxdyp;
    scanf("%d", &usern);
    scanf("%ld", &x0);
    int n=usern+1, nn;
    long a[n];
    for(i=0;i<n;i++) scanf("%ld", &a[i]);
    p=a[0];
    dxdyp=usern*p;
    for(i=1, nn=usern;i<n;i++, nn--){
        p=(p)*x0+a[i];
        dxdyp=(dxdyp)*x0+(nn-1)*a[i];
    }
    if(x0==0) printf("%ld %ld\n", p, a[usern-1]);
        else printf("%ld %ld\n", p, dxdyp/x0);
    return 0;
}