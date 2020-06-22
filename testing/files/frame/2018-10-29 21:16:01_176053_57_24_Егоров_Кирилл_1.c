#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int frame(int height, int width, char *text)
{
    int len = strlen(text);
    int i = 0;
    int j = 0;
    int mid_row = (height - 1) / 2;
    int left = ((width - 2) - len) / 2;
    int right = ((width - 2) - left - len);

    if (((width - 2) < len) || (height < 3))
    {
        printf("Error");
        return 2;
    }

    for (i = 0; i < width; i++)
        printf("*");
    printf("\n");

    for (j = 1; j < height - 1; j++)
    {
        if (j == mid_row)
        {
            printf("*");
            for (i = 0; i < left; i++)
                printf(" ");
            printf("%s", text);
            for (i = 0; i < right; i++)
                printf(" ");
            printf("*\n");
        }
        else
        {
            printf("*");
            for (i = 0; i < width - 2; i++)
                printf(" ");
            printf("*\n");
        }
    }

    for (i = 0; i < width; i++)
        printf("*");
    printf("\n");

    return 0;
}

int main(int argc, char* argv[])
{
    int height = 0;
    int width = 0;
    char *text = NULL;

    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 1;
    }

    height = atoi(argv[1]);
    width = atoi(argv[2]);
    text = argv[3];

    return frame(height, width, text);
}