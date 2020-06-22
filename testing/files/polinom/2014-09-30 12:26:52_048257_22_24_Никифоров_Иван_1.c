//
//  main.c
//  polinom
//
//  Created by Никифоров Иван on 15.09.14.
//  Copyright (c) 2014 NIkif. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{

    int n, i;
    long x, a, a1;
    long sum, pro;
    scanf("%d",&n);
    scanf("%ld", &x);
    scanf("%ld", &a);
    scanf("%ld", &a1);
    
    sum= a*x+a1;
    
    if (n==1)
        pro = a;
     else pro= a * n * x + a1 * (n-1);
 
    for (i=3; i<=n+1; i++){
        scanf("%ld", &a);
        sum=sum * x + a;
        if(i!=n+1)
            pro = pro * x + a*(n+1-i);
    }

    printf("%ld ", sum);
    printf("%ld\n", pro);

    return 0;
}