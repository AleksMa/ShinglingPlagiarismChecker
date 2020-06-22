#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    
    int i = 0, j = 0, n = atoi(*(argv + 1)), m = atoi(*(argv + 2)), p = (m - 2 - strlen(*(argv + 3)))/2;
            
    if (strlen(*(argv + 3)) + 2 > m || n <= 2)
    {
        printf("Error");
        return 0;
    }
        
    for (i = 0; i < m; i++)
    {
        printf("*");
    }
    printf("\n");
    
    for (j = 1; j < n - 1; j++)
    {
        printf("*");
        
        if (j == (n - 1)/2)
        {
            for (i = 0; i < p; i++)
            {
                printf(" ");
            }
            printf("%s", *(argv + 3));
            for (i = 0; i < p + (m%2 - strlen(*(argv + 3))%2)%2; i++)
            {
                printf(" ");
            }
        }
        else
        {
            for (i = 0; i < m - 2; i++)
            {
                printf(" ");
            }
        }
        
        printf("*\n");
    }
    
    for (i = 0; i < m; i++)
    {
        printf("*");
    }
        
    return 0;
}
