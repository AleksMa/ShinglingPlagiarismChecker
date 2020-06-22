#include <stdio.h>

int main(int argc, char **argv)
{ 
    int n;
    long i, p, pr, x0;
    
    //printf("Введите степень полинома \n");
    scanf("%d", &n);
    
    //printf("Введите x0 \n");
    scanf("%ld", &x0);
    
    long *a = (long *) malloc((n+1) * sizeof(long));
    
    p = 0;
    pr = 0;
    
    
    for (i = 0; i <= n; i++)
    {
            //printf("Введите коэффициент полинома ");
            scanf("%ld", &a[i]);
            p = p*x0 + a[i];
            if (i<n) pr = pr*x0 + a[i]*(n-i);
    }
            
    printf("%ld\n", p);
    printf("%ld\n", pr);
    
    free(a);
    return 0;
}