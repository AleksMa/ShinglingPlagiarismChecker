#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) 
{ 
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>\n");
    }
    else {
        int width = atoi(argv[2]);
        int height = atoi(argv[1]);
        if (height < 3 || width < strlen(argv[3]) + 2) {
            printf("Error");
        }
        else {
            for (int i = 0; i < width; i++)
                printf("*");
            printf("\n");
            for (int i = 1; i < height - 1; i++) {
                if (i == (height - 1) / 2) {
                    printf("*");
                    int bound = (width - strlen(argv[3])) / 2;
                    for (int j = 1; j < bound; j++)
                        printf(" ");
                    printf("%s", argv[3]);
                    for (int j = bound + strlen(argv[3]); j < width - 1; j++)
                        printf(" ");
                    printf("*");
                }
                else {
                    printf("*");
                    for (int i = 1; i < width - 1; i++)
                        printf(" ");
                    printf("*");
                }
                printf("\n");
            }
            for (int i = 0; i < width; i++)
                printf("*");
            printf("\n");
        }
    }
    return 0; 
}