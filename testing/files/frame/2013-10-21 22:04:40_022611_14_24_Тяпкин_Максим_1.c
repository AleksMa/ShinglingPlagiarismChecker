#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    int len = strlen(argv[3]);

    if (width - 2 < len || height < 3){
        printf("Error");
        return 0;
    }

    int x = (width - len) / 2;
    int y = (height - 1) / 2;

    int i, j;
    for(i = 0; i < y; i++){
        for(j = 0; j < width; j++){
            (i == 0)||(j == 0)||(j == width - 1) ? printf("*") : printf(" ");
        }
        printf("\n");
    }
    for(i = 0; i < width; i++){
        if (i == 0 || i == width - 1){
            printf("*");
        }else if (i >= x && i < x + len){
            printf("%c", argv[3][i - x]);
        }else printf(" ");
    }
    printf("\n");
    for(i = y + 1; i < height; i++){
        for(j = 0; j < width; j++){
            (i == height - 1)||(j == 0)||(j == width - 1) ? printf("*") : printf(" ");
        }
        printf("\n");
    }
    return 0;
}