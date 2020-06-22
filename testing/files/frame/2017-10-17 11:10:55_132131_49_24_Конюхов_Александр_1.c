#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>");
        return;
    }
    int h=  atoi(argv[1]);
    int w= atoi(argv[2]);
    char *a=argv[3];
    if (strlen(a)>w-2 || h<3)
        printf("Error");
    else
    {
        printf("\n");
        for (int i=0; i<w;i++)
            printf("*");
        printf("\n");


        for (int i=0;i<h-2-(h-2)/2-1; i++)  {
            printf("*");
            for (int i=2; i<w;i++)
                printf(" ");
            printf("*\n");
        }


        printf("*");
        for (int i=0; i<(w-2-strlen(a))/2;i++)
            printf(" ");
        printf ("%s",a);
        for (int i=0; i<w-(w-2-strlen(a))/2-strlen(a)-2;i++)
            printf(" ");
        printf("*\n");


        for (int i=0;i<(h-2)/2; i++){
            printf("*");
            for (int i = 2; i < w; i++)
                printf(" ");
            printf("*\n");
        }


        for (int i=0; i<w;i++)
            printf("*");
    }
    return 0;

}