#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int hei = 0, wid = 0, len = 0;
    char* str;
    hei = atoi(argv[1]);
    wid = atoi(argv[2]);
    str = argv[3];
    len = strlen(str);
    if (hei < 3 || wid < (len + 2)){
        printf("Error");
        return 0;
    }
    int border = (wid - len) / 2;
    for (int j = 0; j < wid; j++)
        printf("*");
    printf("\n");
    for (int i = 1; i < (hei - 1) / 2; i++) {
        printf("*");
        for (int j = 1; j < (wid - 1); j++)
            printf(" ");
        printf("*\n");
    }
    printf("*");
    for (int j = 1; j < border; j++)
        printf(" ");
    printf("%s", str);
    for (int j = (border+len); j < (wid - 1); j++)
        printf(" ");
    printf("*\n");
    for (int i = ((hei - 1) / 2) + 2; i < hei; i++) {
        printf("*");
        for (int j = 1; j < (wid - 1); j++)
            printf(" ");
        printf("*\n");
    }
    for (int j = 0; j < wid; j++)
        printf("*");
    return 0;
}