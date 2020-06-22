#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int j,h,l,x;
    unsigned long int i,y;
    h = atoi(argv[1]);
    l = atoi(argv[2]);
    char *a;
    char b[h][l];
    a = argv[3];
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    if((strlen(a) > (l - 2)) || (h < 3))
    {
        printf("Error");
        return 0;
    }
    y = (l - 2 - strlen(a)) / 2 + 1;
    for (i = 0; h  > i; ++ i)
    {
        for (j = 0; l > j; ++ j)
        {
            b[i][j] = ' ';
        }
    }
    for(i = 0; l > i; ++ i)
    {
        b[0][i] = '*';
        b[h - 1][i] = '*';
    }
    for(i = 1; (h - 1) > i; ++ i)
    {
        b[i][0] = '*';
        b[i][l - 1] = '*';
    }
    if ((h % 2) == 0)
        x = (h - 2) / 2;
    else x = ((h - 2) / 2) + 1;
    j = 0;
    for (i = 0; strlen(a) > i; ++ i)
    {
        b[x][y + i] = a[j];
        ++ j;
    }
    for (i = 0; h  > i; ++ i)
    {
        for (j = 0; l > j; ++ j)
        {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}