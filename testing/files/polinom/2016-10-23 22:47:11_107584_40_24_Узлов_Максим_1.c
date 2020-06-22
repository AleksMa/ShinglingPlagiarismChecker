//
//  polynom.c
//
//
//  Created by Максим Узлов on 23.10.16.
//
//

#include <stdio.h>
int main() {
    long long x0;
    int n;
    scanf("%d%lld", &n, &x0);
    long long a[n+1];
    for(int i = n; i >= 0; --i)
        scanf("%lld", &a[i]);
    //calculate polynom of x0
    long long curValue = a[n];
    for(int i = n - 1; i >= 0; --i) {
        curValue = curValue * x0 + a[i];
    }
    printf("%lld ", curValue);
    //calculate derivative of x0
    curValue = a[n]*n;
    for(int i = n-1; i >= 1; --i) {
        curValue = curValue * x0 + i *a[i];
    }
    printf("%lld", curValue);
    return 0;
    
}

