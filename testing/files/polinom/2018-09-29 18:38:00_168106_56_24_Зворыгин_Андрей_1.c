#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
    long long int n,S,P,i;
    i=0;
    long long int x0;
    scanf("%lli%lli", &n ,&x0);
    n++;
    S=0;
    P=0;
    long long int a[n];
    for( i=0;i<n;i++){
        scanf("%lli", &a[i]);
    }
    S=a[0];
    for(int i=1; i<n ; i++){
        S=S*x0 + a[i];
    }
    for(i=0;i<n;i++){
        a[i]=a[i]*(n-i-1);
    }
    n--;

    P=a[0];
    for(int i=1; i<n ; i++){
        P=P*x0 + a[i];
    }
    printf("%lli %lli\n", S ,P);
    return 0;
}
