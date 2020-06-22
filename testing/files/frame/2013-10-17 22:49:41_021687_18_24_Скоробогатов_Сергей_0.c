#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printntimes(char ch, int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%c", ch);
}

int main(int argc, char** argv) {
    if(argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int h = strtol(argv[1], NULL, 10);
    int w = strtol(argv[2], NULL, 10);
    int slen = strlen(argv[3]);
    if(slen > w - 2 || h < 3) {
        printf("Error");
        return 0;
    } 
    int i;
    for(i = 0; i < h; i++) {
        if(i == 0 || i == h - 1) { 
            printntimes('*', w);
        } else if((h % 2 == 1) ? (i == h / 2) : (i == h / 2 - 1)) {
            printf("*");
            printntimes(' ', (w - slen - 2) / 2);
            printf(argv[3]);
            printntimes(' ', (w - slen - 2) / 2 + (w - slen - 2) % 2);
            printf("*");
        } else {
            printf("*");
            printntimes(' ', w - 2);
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
