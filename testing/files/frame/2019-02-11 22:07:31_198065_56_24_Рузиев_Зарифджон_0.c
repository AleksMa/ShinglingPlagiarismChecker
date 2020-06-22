#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv)
{
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int h = atoi(argv[1]), w = atoi(argv[2]), len_str = strlen(argv[3]);

    int i, j = 1;
    if (h < 3 || w -2 < len_str){
        printf("Error\n");
        return 0;
    }

    for (i = 0; i < w; i++) printf("*");
    printf("\n");
    for (i = 1; i < h; i++){
        if (i == h - 1){
           for (i = 0; i < w; i++) printf("*");
           break;
        }
        while(j < w + 1){
            if(j == 1){
                printf("*");
                j++;
            }
            if (i == h/2 - ((h + 1) % 2) && j == (w - len_str)/2 + 1){
                printf("%s", argv[3]);
                    j += len_str;
            }
                else{
                     printf(" ");
                    j++;
                }
        if (j == w){
            printf("*");
            j++;
            }
        }
        j = 1;
        printf("\n");

    }
    return 0;
}