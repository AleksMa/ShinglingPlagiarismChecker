#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1(unsigned long n)
{
    int i;
    for ( i = 0; i < n; i++)
        printf("*");
}

void fun2(int n)
{
    int i;
    printf("*");
    for ( i = 1; i < n - 1; i++)
        printf(" ");
    printf("*");
    printf("\n");
}

void fun3(int n, int p, char *s, int l)
{
    unsigned long i;
    printf("*");
    for ( i = 1; i < p - 1 ; i++)
        printf(" ");
    printf("%s", s);
    for ( i = p + l; i < n; i++)
        printf(" ");
    printf("*");
    printf("\n");
}

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *text = argv[3] ;
    int l,x,y,i;
    l=strlen(text);
    if ((l+2 > width) || ( height < 3))
        printf("Error");
    else
    {
        x=(width - l)/2 + 1;
        y=height/2 + (height % 2);
        fun1(width);
        printf("\n");
        for ( i = 1; i < height - 1; i++)
            if ( i != y - 1)
                fun2(width);
            else
                fun3(width,x,text,l);
        fun1(width);
    }
    return 0;
}
