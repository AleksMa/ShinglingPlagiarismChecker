#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 4){printf("Usage: frame <height> <width> <text>"); return 0;}
    if ((atoi(argv[1]) < 3) || (atoi(argv[2]) - 2 < (strlen(argv[3])))) {printf("Error"); return 0;}
    int d = atoi(argv[2]), t = atoi(argv[1]), len = strlen(argv[3]);
    for(int j = 0; j < d; j++)
        printf("*");
    printf("\n");
    for(int i = 1; i <= (t - 3) / 2; i++)
    {
        printf("*");
        for(int j = 1; j < d - 1; j++)
            printf(" ");
        printf("*\n");
    }
    printf("*");
    for(int j = 1; j < (d-len)/2; j++)
        printf(" ");
    printf("%s", argv[3]);
    for(int j = 1; j < (d-len+1)/2; j++)
        printf(" ");
    printf("*\n");
    for(int i = 1; i <= (t - 2) / 2; i++)
    {
        printf("*");
        for(int j = 1; j < d - 1; j++)
            printf(" ");
        printf("*\n");
    }
    for(int j = 0; j < d; j++)
        printf("*");
    printf("\n");
    return 0;
}