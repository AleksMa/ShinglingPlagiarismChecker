#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *word = argv[3];
    int height, width, i, j, n;
    if (argc != 4)
        printf("Usage: frame <height> <width> <text>\n");
    else
    {
        n = strlen(word), height = atoi(argv[1]), width = atoi(argv[2]);
        if (n >= width - 1 || height < 3)
            printf("Error\n");
        else
        {
            for (i = 0; i < width; putchar('*'), ++i);
            for (putchar('\n'), i = 1; ++i < height; putchar('\n'))
                for (j = 0; j < width; ++j)
                {
                    putchar(j == 0 || j == width - 1 ? '*' : ' ');
                    if (i == ((height - 1) >> 1) + 1 && j == ((width - n) >> 1) - 1)
                        printf("%s", word), j += n;
                }
            for (i = 0; i < width; putchar('*'), ++i);
            putchar('\n');
        }
    }
    return 0;
}