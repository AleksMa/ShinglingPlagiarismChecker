#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    char * s = argv[3];
    int len_s = strnlen(s, 1000);
    if (n < 3 || m < len_s + 2) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < m; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < ((n - 2) + 1) / 2 - 1; i++) {
        printf("*");
        for (int j = 0; j < m - 2; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    printf("*");
    for (int i = 0; i < (m - len_s - 2) / 2; i++) {
        printf(" ");
    }
    for (int i = 0; i < len_s; ++i) {
        printf("%c", s[i]);
    }
    for (int i = 0; i < ((m - len_s - 2) + 1) / 2; i++) {
        printf(" ");
    }
    printf("*");
    printf("\n");
    for (int i = 0; i < (n - 2) / 2; i++) {
        printf("*");
        for (int j = 0; j < m - 2; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < m; i++) {
        printf("*");
    }
    return 0;
}