#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc == 4){
        int w = atoi(argv[2]), h = atoi(argv[1]), size = strnlen(argv[3], 1000);
        int WL = (w - size) / 2 - 1, WR = (WL + size), H = (h - 1) / 2 - 1;
        if ((h > 2) && ((w - 2) >= size)){
            for (int i = 0; i < w; ++i)
            printf("*");
            for (int i = 0; i < h - 2; ++i){
                printf("\n*");
                for (int j = 0; j < w - 2; ++j)
                if (H == i && (j >= WL) && (j < WR))
                printf("%c", argv[3][j - WL]);
                else
                printf(" ");
                printf("*");
            }
            printf("\n");
            for (int i = 0; i < w; ++i)
            printf("*");
            printf("\n");
        } else
        printf("Error\n");
    } else
    printf("Usage: frame <height> <width> <text>\n");
    return 0;
}