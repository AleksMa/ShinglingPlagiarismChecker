#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, j, k, r;
    int h, w;
    char *s;
    int ws;

    if (argc < 3)
    {
        printf("usage: frame <height> <width> <text> \n");
        exit(0);
    }

    h = atoi(argv[1]);
    w = atoi(argv[2]);
    s = argv[3];
    ws = strlen(s);

    if (w < ws + 2 || h < 3)
    {
        printf("Error \n");
        exit(0);
    }

    for(i = 0; i < w; i++)
        printf("%c",'*');
    printf("\n");

    k = h%2 ? h/2 : h/2 - 1;
    for(i = 1; i < k; i++)
    {
        printf("%c",'*');
        for(j = 0; j < w - 2; j++) printf("%c", ' ');
        printf("%c\n",'*');
    }

    r = (w - 2 - ws);
    r = r%2 ? r/2 : r/2 - 1;
    printf("%c",'*');
    for(i = 0; i <= r ; i++)
        printf("%c", ' ');
    i++;
    for(j = 0; j < ws; j++)
        printf("%c", s[j]);
    for(i += ws; i < w - 1; i++)
        printf("%c", ' ');
    printf("%c\n",'*');

    for(i = k + 1; i < h - 1; i++)
    {
        printf("%c",'*');
        for(j = 0; j < w - 2; j++) printf("%c", ' ');
        printf("%c\n",'*');
    }

    for(i = 0; i < w; i++)
        printf("%c",'*');
    printf("\n");

    return 0;
}
