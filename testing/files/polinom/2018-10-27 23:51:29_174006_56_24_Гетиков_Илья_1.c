#include <stdio.h>

int main(int argc, const char * argv[]) {
    long n,x,i;
    scanf("%ld", &n);
    scanf("%ld", &x);
    long arr[n];
    for (i = 0; i <= n; i++){
        scanf("%ld", &arr[i]);
    }
    long summ = 0;
    for (i = 0 ; i <= n ;i++){
        summ = summ * x + arr[i];
    }
    long pro = 0;
    for (i = 1 ; i <= n;i++){
        pro = pro * x + (n -i + 1) * arr[i-1];
    }
    printf("%ld ", summ);
    printf("%ld\n", pro);
    return 0;
}
