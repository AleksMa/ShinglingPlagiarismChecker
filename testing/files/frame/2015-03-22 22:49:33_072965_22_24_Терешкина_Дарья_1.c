#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mstrlen (char *str)
{
    int i;
    for(i = 0; (str[i] != '\n' && str[i] != '\0'); i++);
    return i;
}

void print(int j, int width)
{
    printf((j == 0 || j == width - 1) ? "*" : " ");
}

void print1 (int width)
{
    int i;
    for (i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int height, width, i, j, n;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
    }
    else
    {
        n = mstrlen(argv[3]);
        height = atoi(argv[1]);
        width = atoi(argv[2]);
        if (n >= width - 1 || height < 3)
        {
            printf("Error\n");
        }
        else
        {
            print1(width);
            for (i = 1; ++i < height; printf("\n"))
            {
                for (j = 0; j < width; ++j)
                {
                    print(j, width);
                    if (i == ((height - 1) / 2) + 1 && j == ((width - n) / 2) - 1)
                    {
                        printf("%s", argv[3]);
                        j += n;
                    }
                }
            }
            print1(width);
        }
    }
    return 0;
}