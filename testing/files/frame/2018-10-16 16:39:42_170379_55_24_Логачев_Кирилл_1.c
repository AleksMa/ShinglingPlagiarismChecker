#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc == 4){
        int w = atoi(argv[2]);
        int h = atoi(argv[1]);
        int size = strnlen(argv[3], 1000);
        int StrWL = (w - size) / 2 - 1;
        int StrWR = (StrWL + size);
        int StrH = (h - 1) / 2 - 1;
        if ((h > 2) && ((w - 2) >= size)){
            //printf("%d %d\n", StrW, StrH);
            for (int i = 0; i < w; ++i)
                printf("*");
            for (int i = 0; i < h - 2; ++i){
                printf("\n*");
                for (int j = 0; j < w - 2; ++j)
                    if (StrH == i && (j >= StrWL) && (j < StrWR))
                        printf("%c", argv[3][j - StrWL]);
                    else
                        printf(" ");
                printf("*");
            }
            printf("\n");
            for (int i = 0; i < w; ++i)
                printf("*");
            printf("\n");
            //printf("%s\n", argv[3]);
        } else
            printf("Error\n");
    } else
        printf("Usage: frame <height> <width> <text>\n");
    return 0;
}
