#include <stdio.h>

long int horner_scheme(int poly[], int n, int x)
{
    long int res = poly[0];
 
    for (int i=1; i<n; i++)
        res = res*x + poly[i];
    return res;
}


int main()
{
    int max_pol, x, i, k;
    
    scanf("%d",&max_pol);
    scanf("%d",&x);
    int size_array = max_pol + 1;
    int poly[size_array];
    
    for(i=0; i<size_array; i++){
        scanf("%d",&k);
        poly[i] = k;
    }
    long int value_func = horner_scheme(poly, size_array, x);
    int size_array_def = size_array - 1; 
    
    int poly_def[size_array_def];    
    for(i=0; i<size_array_def; i++) poly_def[i] = poly[i]* (size_array_def - i);
    
    long int def_value = horner_scheme(poly_def, size_array_def, x);
    
    printf("%li %li", value_func, def_value);
    return 0;
}