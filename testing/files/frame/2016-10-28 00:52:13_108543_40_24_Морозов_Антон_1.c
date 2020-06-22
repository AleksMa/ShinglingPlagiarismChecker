#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    int h, w, i, j, k, len;
    char *p;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    //scanf("%d %d \n", &h, &w);
    h = atoi(argv[1]);
    w = atoi(argv[2]);
    //p = (char*)malloc((w-1)*(sizeof(char)));
    //gets(p);
    p = argv[3];
    len = strlen(p);
    if ((len > (w - 2)) || (h < 3) || (w < 3)) // -1
    {
        printf("Error");
        return 0;
    }
    for (i = 0; i < w; i++)
        printf("*");
    printf("\n");
    k = (h - 1) / 2;
    for (i = 1; i < k; i++)
    {
        printf("*");
        for (j = 1; j < (w - 1); j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    printf("*");
    for (i = 0; i < (w - 2 - len) / 2; i++)
        printf(" ");
    printf("%s", p);
    for (i = 0; i < (w - 1 - len) / 2; i++)
        printf(" ");
    printf("*");
    printf("\n");
    for (i = (h + 1) / 2; i < h - 1; i++)
    {
        printf("*");
        for (j = 1; j < (w - 1); j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    for (i = 0; i < w; i++)
        printf("*");
    return 0;
}
