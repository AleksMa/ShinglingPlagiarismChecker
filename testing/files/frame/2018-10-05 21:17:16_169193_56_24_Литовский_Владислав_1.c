#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        unsigned int l = strlen(argv[3]);
        unsigned int h = atoi(argv[1]), w = atoi(argv[2]);
        if ((l <= w - 2) && (h >= 3))
        {
            for (unsigned int i = 0; i < w; i++)
                printf("*");
            printf("\n");
            for (unsigned int i = 1; i < h - 1; i++)
            {
                printf("*");
                if (i == (h - 1) / 2)
                {
                    for (unsigned int j = 1; j < (w - l) / 2; j++)
                        printf(" ");
                    printf("%s", argv[3]);
                    for (unsigned int j = (w - l) / 2 + l; j < w - 1; j++)
                        printf(" ");
                }
                else
                {
                    for (unsigned int j = 1; j < w - 1; j++)
                        printf(" ");
                }
                printf("*\n");
            }
            for (unsigned int i = 0; i < w; i++)
                printf("*");
        }
        else
            printf("Error");
    }
    else
        printf("Usage: frame <height> <width> <text>");
    return 0;
}
