#include <stdio.h> 

int main() 
{ 
        int n, x; 
        scanf("%d %d", &n, &x); 
        int mass[n+1]; 

        for(int f = 0; f < n + 1; f++) 
                scanf("%d", &mass[f]); 

        long result = mass[0]; 
        
        for (int g = 1; g < n + 1; g++) 
                result = result * x + mass[g]; 

        long result2 = mass[0] * n; 
        
        for (int i = 1; i < n; i++) 
                result2 = result2 * x + mass[i] * (n - i); 
        
        printf("%ld %ld", result, result2); 
        return 0; 
}