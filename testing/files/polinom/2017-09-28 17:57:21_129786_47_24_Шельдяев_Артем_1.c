//
//  main.c
//  Task1
//
//  Created by Artyom Sheldyaev on 20.09.17.
//  Copyright © 2017 Artyom Sheldyaev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    n += 1;
    long long x;
    scanf("%ld", &x);
    long long arr[n];
    
    for(int i = 0; i < n; i++) {
        long long curr;
        scanf("%ld", &curr);
        arr[i] = curr;
    }
    
    long long polynom = arr[0] * x + arr[1];
    
    for(int i = 2; i < n; i++) {
        polynom *= x;
        polynom += arr[i];
    }
    
    printf("%ld ", polynom);
    
    for(int i = 0; i < n; i++) {
        arr[i] *= (n - i - 1);
    }
    
    if(n == 2) {
        printf("%ld", arr[0]);
        return 0;
    }
    
    long long s_polynom = arr[0] * x + arr[1];
    
    for(int i = 2; i < n - 1; i++) {
        s_polynom *= x;
        s_polynom += arr[i];
    }
    
    printf("%ld", s_polynom);
    return 0;
}
