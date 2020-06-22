#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4) {printf("Usage: frame <height> <width> <text>\n"); return -1;}
    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    char* t = argv[3];
    if ((strlen(t) > w-2) || (h < 3)) {printf("Error\n"); return -2;}
    for (int i = 0; i < h; i++)
    {
        if ((i == 0) || (i == h-1))
        {
            for (int j=0; j < w; j++) printf("*");
        } else if (i == (h+1)/2-1) {
            int spl = (w-2-strlen(t))/2;
            int spr = w-2-strlen(t)-spl;
            printf("*");
            for(int j=0; j < spl; j++)
            {
                printf(" ");
            }
            printf("%s", t);
            for(int j=0; j < spr; j++)
            {
                printf(" ");
            }
            printf("*");
        } else {
            printf("*");
            for(int j=0; j<w-2; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}