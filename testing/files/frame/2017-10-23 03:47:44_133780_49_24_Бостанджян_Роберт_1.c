#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        exit(-1);
    }
    int i = 0;
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *text = argv[3];
    int len = (int)strlen(text);
    
    if ((strlen(text) > width - 2) || (height < 3)) {
        printf("Error\n");
        exit(-1);
    }
    
    for (i = 0; i < width; i++)
        printf("%c", 42);
    printf("\n");
    
    for (i = 0; i < height - 2; i++) {
        if (i == (height + 1)/2 - 2) {
            printf("%-*c", (width - len)/2, 42); 
            printf("%*s", len, text);
            printf("%*c\n", (width - len + 1)/2, 42);
        } else {
            printf("%c", 42);
            printf("%*c\n", (width - 1), 42);
        }
    }
    
    for (i = 0; i < width; i++)
        printf("%c", 42);
    printf("\n");
    
    return 0;
}