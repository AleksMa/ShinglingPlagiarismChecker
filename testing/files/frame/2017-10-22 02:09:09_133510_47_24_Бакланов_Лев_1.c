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
    long higth = atoi(argv[1]);
    long width = atoi(argv[2]);
    long length = strlen(argv[3]);
    if ((higth < 3) || (width-1 <= length))
    {
        printf("Error");
        return 0;
    }
    long coord_higth = (higth + 1) / 2;
    long coord_width = (width - length) / 2;
    for (int i = 0; i < width; i++) printf("*");
    for (int i = 0; i < (higth - 3)/2; i++)
    {
        printf("\n");
        printf("*");
        for (int j = 0; j < width-2; j++) printf(" ");
        printf("*");
    }
    printf ("\n*");
    for (int i = 0; i < coord_width - 1; i++) printf(" ");
    printf(argv[3]);
    for (int i = 0; i < (width - length - 1) / 2; i++) printf(" ");
    printf("*\n");
    for (int i = 0; i < (higth - 2)/2; i++)
    {
        printf("*");
        for(int j = 0; j < width - 2; j++) printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < width; i++) printf("*");
}


