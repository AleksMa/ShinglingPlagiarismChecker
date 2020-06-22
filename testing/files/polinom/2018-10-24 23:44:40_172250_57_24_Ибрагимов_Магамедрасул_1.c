#include <stdio.h>

int main(){
        long long x , func , der;
	int n , a;
    scanf("%d" , &n);
    scanf("%lli" , &x);
    long long koef[(n+1)];
    for(a = 0 ; a <= n ; a++){
    	scanf("%lli" , &koef[a]);
    }
    func = koef[0];
    der = koef[0]*n;
    for(a = 1; a <= n ; a++){
        func = func * x + koef[a];	
    }
    printf("%lli" , func);
    for(a = 1 ; a < n ; a++){
    	der = der*x + koef[a]*(n-a);
    }
    printf(" %lli" , der);
}