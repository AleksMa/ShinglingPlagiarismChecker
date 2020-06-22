#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, x, i;
    int *a;
    long int answer = 0, answer2 = 0;
    scanf("%d", &n);
    scanf("%d", &x);

    a = (int *) malloc ((n+1) * (sizeof(int)));
    for(i=0;i<=n;i++){
        scanf("%d", &a[i]);
    }

    answer = a[0];
    for(i=1;i<=n;i++){
        answer = answer * x + a[i];
    }
    printf("%ld\n", answer);

    
    
    for(i=0;i<=n;i++){
        a[i] = a[i] * (n - i);
    }
    
    answer2 = a[0];
    for(i=1;i<n;i++){
        answer2 = answer2 * x + a[i];
    }
    
    free(a);
    printf("%ld\n", answer2);
    
    return 0;
}