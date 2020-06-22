#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 4) printf("Usage: frame <height> <width> <text>");
    
    else {
        int height = atoi(argv[1]);
        int width = atoi(argv[2]);
        
        if ((height < 3) || (width < strlen(argv[3]) + 2)) {
            printf("Error");
            return 0;
        }
        
        char output[height][width];
        int i, j;
        
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++)
                if ((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
                    output[i][j] = '*';
                else output[i][j] = ' ';
        
        int len = strlen(argv[3]);
        int m = (height - 1)/ 2;
        int n = (width - len) / 2;
        
        for (i = n, j = 0; len > 0; i++, j++, len--)
            output[m][i] = argv[3][j];
            
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++) {
                printf("%c", output[i][j]);
                if (j == width - 1)
                    printf("\n");
            }
    }
        
    return 0;
}