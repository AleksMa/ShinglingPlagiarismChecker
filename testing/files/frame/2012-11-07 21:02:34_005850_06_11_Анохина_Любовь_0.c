#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char **argv)
{
    int k, i, n = 0,dl, high, width;
    if (argc != 4)
    {
        printf("usage: frame <height> <width> <text>\n");
        return 0;
    } 
    else 
    {   dl = strlen(argv[3]);
        high = atoi(argv[1]);
        width = atoi(argv[2]);
        if ( high > 2 && width > dl + 1)
        {
            char **ram;
            ram = (char**)malloc(high * sizeof(char*));
            for ( k = 0; k < high; ++k)
            {
                ram[k] = (char*)malloc(width * sizeof(char));
                
            }
 
            for ( k = 0; k < high; ++k)
            {
                for ( i = 0; i < width; ++i)
                {
                    if ( k == 0 || i == 0 || k == high - 1 || i == width - 1) ram[k][i] = '*';
                
                    else
                        if ( (k == (high - 1)/2) && (i > ( width - 2 - dl)/2) && (i < ( width - 1- (width - 1 - dl)/2)))
                            ram[k][i] = argv[3][++n];
                        else
                            ram[k][i] = ' ';
                            
                }
                            
            }
            for ( k = 0; k < high; ++k)
            {
                for ( i = 0; i < width; ++i)
                    printf("%c", ram[k][i]);
                printf("\n");
            }
        } 
        else
            printf("Error\n");
    }
    return 0;
}