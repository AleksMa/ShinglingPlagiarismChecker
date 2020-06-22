
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
     int height, width, i, j, f, k;
     char* slovo = " ";

    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    height = atoi (argv[1]);
    width = atoi (argv[2]);
    slovo = argv[3];
    if ((height < 3) || (width < strlen(slovo) + 2 ))
    {
            printf("Error");
            return 0;
    }

    else
    {
        for (i = 0; i < width; i++)
            printf("*");
        printf("\n");

        if (height % 2 == 0)
        {
            f = height / 2 - 2;
            k = height - f - 3;
        }
        else
        {
            f = height / 2 - 1;
            k = f;
        }
        for (i = 0; i < f; i++)
        {
            printf("*");
            for (j = 0; j < width - 2; j++)
                printf(" ");
            printf("*\n");
        }
        printf("*");

        for (j = 0; j < (width - 2 - strlen(slovo)) / 2; j++)
            printf(" ");
        printf("%s", slovo);
        for (j = 0; j < (width - 1 - strlen(slovo)) / 2 ; j++)
            printf(" ");
        printf("*\n");

        for (i = 0; i < k; i++)
        {
            printf("*");
            for (j = 1; j < width - 1; j++)
                printf(" ");
            printf("*\n");
        }
        for (i = 0; i < width; i++)
            printf("*");
        printf("\n");
    }
    return 0;

}