#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int len = strlen(argv[3]);
    int i, j;
    int mid = x >> 1;
    if (!(x & 1))
        mid -= 1;

    if ((x > 2) && (y > len + 1)) {
        for (j = 0; j < y; j++)
                    if (j == (y - 1))
                        printf("*\n");
                    else printf("*");
                    
        for (i = 1; i < x - 1; i++) {
            if (i == mid) {
                printf("*");
                for (j = 0; j < (y-len-2)/2; j++)
                    printf(" ");
                printf(argv[3]);
                for (j = 0; j < (y-len-1)/2; j++)
                    printf(" ");
                printf("*\n");
            } 
            else {
                printf("*");
                for (j = 0; j < y -2; j++)
                    printf(" ");
                printf("*\n");
            }
        }
        
        for (j = 0; j < y; j++)
            if (j == (y - 1)) 
                printf("*\n");
            else printf("*");
            
    }
    else printf("Error\n");
    return 0;
}