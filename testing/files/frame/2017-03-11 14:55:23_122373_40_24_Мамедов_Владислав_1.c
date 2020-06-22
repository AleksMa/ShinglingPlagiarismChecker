#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int args, char **argv) {
    int i, j, height = atoi(argv[1]), width = atoi(argv[2]);
    if(args < 4) {printf("Usage: frame <height> <width> <text>\n"); return -1;}
    if(height < 3 || width < strlen(argv[3]) + 2) {printf("Error\n"); return -2;}
    
    for(j = 0; j < width; ++j) printf("*");
    printf("\n");
    int middle = (height % 2 == 0) ? height / 2 - 1 : height / 2;
    for(i = 1; i < middle; ++i) {
        printf("*");
        for(j = 0; j < width - 2; ++j) printf(" ");
        printf("*\n");
    }
    
    printf("*");
    int tab = (width - strlen(argv[3]) - 2);
    for(j = 0; j < tab / 2; ++j) printf(" ");
    printf("%s", argv[3]);
    for(; j < tab; ++j) printf(" ");
    printf("*\n");
    
    for(i = middle + 1; i < height - 1; ++i) {
        printf("*");
        for(j = 0; j < width - 2; ++j) printf(" ");
        printf("*\n");
    }
    
    for(j = 0; j < width; ++j) printf("*");
    printf("\n");
    
    return 0;
}