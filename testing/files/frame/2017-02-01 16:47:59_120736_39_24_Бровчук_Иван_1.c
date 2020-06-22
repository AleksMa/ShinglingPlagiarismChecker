#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char r ( int n);
char r ( int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("*");
    printf("\n");
    return 0;
}
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        goto here;
    }
    int i, j , h = atoi(argv[1]), w = atoi(argv[2]), len = (int)strlen(argv[3]), m1, m2;
    if (h < 3 || w - 2  < len)
    {
        printf("Error\n");
        goto here;
    }
    m1 = ((w - len) / 2);
    m2 = h/2 + h % 2;
    r(w);
    for (i = 2; i < h; i++)
    {
        for (j = 1; j < w; j++)
        {
            if (j == 1 || j == w-1)
                printf("*");
            if (j >= m1 && i == m2 && j < m1 + len)
                printf("%c", argv[3][j-m1]);
            else
                printf(" ");
        }
        printf("\n");
    }
    r(w);
here:
    return 0;
}
