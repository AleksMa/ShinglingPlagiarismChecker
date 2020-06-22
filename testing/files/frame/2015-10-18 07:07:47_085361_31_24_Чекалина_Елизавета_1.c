#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    if (argc!=4)
    {
        printf("Usage: frame <height> <width> <text>");
        exit(0);
    };
    int w, h, i, j, len, hh, wh;
    h = atoi(argv[1]);
    if (h<=2)
    {
        printf("Error");
        exit(0);
    };
    w = atoi(argv[2]);
    char s[19];
    strcpy(s,argv[3]);
    len=strlen(s);
    if (w<len+2)
    {
        printf("Error");
        exit(0);
    };
//начинаем рисование
    for (i=1; i<=w; i++) printf("*");
    printf("\n");
    for (i=1; i<=(h-3)/2; i++)
    {
        printf("*");
        for (j=1; j<=w-2; j++) printf(" ");
        printf("*\n");
    }
    printf("*");
    for (i=1; i<=(w-2-len)/2; i++) printf(" ");
    printf("%s", s);
    if ((w%2==0)&&(len%2!=0)||(w%2!=0)&&(len%2==0)) wh=(w-2-len)/2+1;
    else wh=(w-2-len)/2;
    for (i=1; i<=wh; i++) printf(" ");
    printf("*\n");
    if ((h%2)==0) hh=(h-3)/2+1;
    else hh=(h-3)/2;
    for (i=1; i<=hh; i++)
    {
        printf("*");
        for (j=1; j<=w-2; j++) printf(" ");
        printf("*\n");
    }
    for (i=1; i<=w; i++) printf("*");
    return 0;
}
