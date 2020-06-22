#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int i, j, k = 0, h = atoi(argv[1]), l = atoi(argv[2]), lens = strlen(argv[3]);
    if ((l - 2 < lens) || (h < 3))
    {
        printf("Error\n");
        return 0;
    }
    char frame[h][l];
    int beg = (l - lens + 2) / 2 - 1;
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < l; ++j)
        {
            frame[i][j] = ' ';
        }
    }
    for (i = 0; i < l; ++i) frame[0][i] = '*';
    for (i = 1; i < h-1; ++i)
    {
        frame[i][0] = '*';
        frame[i][l-1] = '*';
        if (i == (h + 1) / 2 - 1)
        {
            for (j = beg; j < beg + lens; ++j)
            {

                frame[i][j] = argv[3][k];
                k++;
            }
        }
    }
    for (i = 0; i < l; ++i) frame[h-1][i] = '*';
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < l; ++j)
        {
            printf("%c",frame[i][j]);
        }
        printf("\n");
    }
    return 0;
}