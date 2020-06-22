#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wall (int h, int w)
{
    for (int i = 0; i <((h - 2)/2); i++)
    {
        printf("*");
        for (int j = 0; j < (w - 2); j++) printf(" ");
        printf("*");
        printf("\n");
    }
}

void top(int w)
{
    for (int i = 0; i < w; i++) printf("*");
    printf("\n");
}

void filling(int w, char *text)
{
    unsigned long size = strlen(text), w1,w2;
    w1 = ((w - 2) - size) / 2;
    w2 = ((w - 2) - size) - w1;
    printf("*");
    for (int i = 0; i < w1; i++) printf(" ");
    printf("%s", text);
    for (int i = 0; i < w2; i++) printf(" ");
    printf("*");
    printf("\n");
}

int main(int argc , char *argv[])
{
    int h, w;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    h = atoi(argv[1]);
    w = atoi(argv[2]);
    char *text = argv [3];
    unsigned long x = strlen(text);
    if (((w - 2) < x) || (h <= 2))
    {
        printf("Error");
        return 0;
    }
    top(w);
    if ((h % 2) == 1) wall(h, w);
    else wall((h - 1), w);
    filling(w,text);
    wall(h, w);
    top(w);
    return 0;
}

