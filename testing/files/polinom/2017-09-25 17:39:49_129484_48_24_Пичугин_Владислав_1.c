#include<stdio.h>
int main(){
    long n,x,i;
    scanf("%ld%ld",&n,&x);
    long k[n+1];
    for (i=0;i<=n;i++)
        scanf("%ld",&k[i]);
    long pol=k[0],prozpol=n*k[0];
    for (i=0;i<n;i++){
        pol*=x;
        pol+=k[i+1];
    }
    for (i=0;i<(n-1);i++){
        prozpol*=x;
        prozpol+=(n-i-1)*k[i+1];
    }
    printf("%ld %ld",pol,prozpol);
    return 0;
}
