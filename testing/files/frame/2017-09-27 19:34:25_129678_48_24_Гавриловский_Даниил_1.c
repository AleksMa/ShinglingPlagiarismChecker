//Finish version
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

    int height = atoi(argv[1]), width = atoi(argv[2]);
    char *text = argv[3];

    if (strlen(text) > width - 2 || height < 3)
    {
        printf("Error");
        return 0;
    }

    for (int i = 0; i < width; i++)
        printf("*");

    int need_line = (height - 1) / 2;
    int need_pos = width / 2 - (strlen(text) + !(width % 2)) / 2;

    printf("\n");
    for (int i = 1; i < height - 1; i++)
    {
        printf("*");
        for (int j = 1; j < width - 1; j++)
        {

            if (i == need_line && j == need_pos)
            {
                printf("%s", text);
                j += strlen(text) - 1;
            }
            else
                printf(" ");

        }
        printf("*\n");
    }

    for (int i = 0; i < width; i++)
        printf("*");

    return 0;
}