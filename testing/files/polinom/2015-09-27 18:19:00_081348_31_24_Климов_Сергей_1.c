
#include <stdio.h>

int main(int argc, char **argv)
{ 
        int i=0, n=0 , x=0, m=0;
        long long int summ1=0  ,summ2=0 ;
        scanf("%d %d", &n , &x);
        int arr[n+1];
        for(i=0;i<=n;i++) scanf("%d",&arr [i]);
        summ1 = arr[0];
        summ2 = n*arr[0];
        m = n;
        for(i=0;i<=(m-1);(i++,n--)){
                summ1 = summ1 * x + arr[i+1];
                if (i==(m-1)) summ2=summ2;
                else summ2 = summ2 * x + (n-1)*arr[i+1];
        }
        printf("%lld %lld\n", summ1 , summ2);
        return 0; 
}  
 