#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    long len = atoi(argv[1]), wid = atoi(argv[2]), count = strnlen(argv[3], 255);
    int i, j = 0;
    if ((count > wid-2) || (len < 3)) printf("Error");
    else {
        for (i = 0; i < wid; i++) printf("*");
        printf("\n");
        for (i = 0; i < len - 2; i++){
            if (i != (len + 1)/2 - 2){
                for (j = 0; j < wid; j++){
                    if ((j != 0) && (j != (wid - 1))) printf(" ");
                    else printf("*");
                }
                printf("\n");
            } else {
                printf("*");
                for (j = 0; j < (wid - count - 2)/2; j++) printf(" ");
                printf("%s", argv[3]);
                for (j = (wid - count)/2 + count; j < wid - 1; j++) printf(" ");
                printf("*");
                printf("\n");
            }
        }
        for (i = 0; i < wid; i++) printf("*");
    }
    printf("\n");
    return 0;
}
