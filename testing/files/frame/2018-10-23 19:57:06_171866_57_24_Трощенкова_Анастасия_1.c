#include <stdio.h>
#include <string.h>

int natoi (char *s)
{
    int sum = 0, i;
    for (i = 0; s[i] != 0; i++)
    {
        sum = sum*10 + s[i] - '0';
    }
    return sum;
}

int main(int argc, char **argv)
{
    int height, width, i, j, m, k1, k2, c;
    char *s;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    height = natoi(argv[1]); width = natoi(argv[2]);
    s = argv[3];
    m = strlen(s);
    if (m + 2 > width || height < 3)
    {
        printf("Error\n");
        return 0;
    }
    if (height % 2 == 0)
    {
        c = height/2;
    }
    else
    {
        c = height/2 + 1;
    }
    for (i = 1; i <= height; i++)
    {
        if (i == 1 || i == height)
        {
            for (j = 0; j < width; j++)
            {
                printf("*");
            }
        }
        else if (i != c)
        {
            printf("*");
            for (j = 0; j < (width - 2); j++)
            {
                printf(" ");
            }
            printf("*");
        }
        else
        {
            k1 = (width - (m + 2))/2;
            k2 = width - 2 - m - k1;
            printf("*");
            for (j = 0; j < k1; j++)
            {
                printf(" ");
            }
            printf("%s", s);
            for (j = 0; j < k2; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}