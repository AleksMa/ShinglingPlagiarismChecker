#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int hor, ver, len, i, j;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    ver = atoi(argv[1]);
    hor = atoi(argv[2]);
    len = strlen(argv[3]);
    
    if ((hor - len) < 2)
    {
        printf("Error");
        return 0;
    }
    if (ver < 3)
    {
        printf("Error");
        return 0;
    }
    
    for (i = 0; i < hor; i++)
        printf("*");
    
    printf("\n");
    
    
    for (i = 1; i < (ver / 2) + (ver % 2) - 1; i++)
    {
        printf("*");
        for (j = 0; j < (hor - 2); j++)
            printf(" ");
        printf("*\n");
    }
    
    printf("*");
    
    for (j = 0; j < (hor - 2 - len) / 2; j++)
        printf(" ");
    
    printf("%s",argv[3]);
    
    for (j = 0; j < (hor - 2 - len) / 2 + (hor - 2 - len) % 2; j++)
        printf(" ");
    printf("*\n");
    
    for (i+=2; i < ver; i++)
    {
        printf("*");
        for (j = 0; j < hor - 2; j++)
            printf(" ");
        printf("*\n");
    }
    for (i = 0; i < hor; i++)
        printf("*");
    
    return 0;
}