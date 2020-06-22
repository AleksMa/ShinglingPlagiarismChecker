#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }

    const char * text = argv[3];
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    int len = strlen(text);

    if (len > width - 2 || height < 3)
    {
        printf("Error");
        return 2;
    }

    int line = (height + 1) / 2 - 1;
    int empty = width - 2 - len;
    int empty_left = empty / 2;
    int empty_right = empty - empty_left;

    int i, j;

    for (i = 0; i < height; i++)
    {
        if (i == 0 || i == height - 1)
        {
            for (j = 0; j < width; j++)
                printf("*");
        }
        else if (i == line)
        {
            printf("*");
            for (j = 0; j < empty_left; j++)
                printf(" ");
            printf("%s", text);
            for (j = 0; j < empty_right; j++)
                printf(" ");
            printf("*");
        }
        else
        {
            printf("*");
            for (j = 0; j < width - 2; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    return 0;
}