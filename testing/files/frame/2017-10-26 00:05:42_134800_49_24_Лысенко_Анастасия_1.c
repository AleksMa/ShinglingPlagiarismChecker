
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int a = atoi(argv[1]), b = atoi(argv[2]);
    char* chr = argv[3];
    int n = strlen(chr);
    if ((n + 2 <= b) && (a > 2)) {
        for (int i = 0; i < b; i++)
            printf("*");
        printf("\n");

        int k = 0;
        if (a%2 == 1)
            while (k < a/2 - 1) { 
                printf("*");
                for (int j = 0; j < b - 2; j++)
                    printf(" ");
                printf("*");
                printf("\n");
                k++; 
            } 
        else while (k < a/2 - 2) {
                printf("*");
                for (int j = 0; j < b - 2; j++)
                    printf(" ");
                printf("*");
                printf("\n");
                k++;
            }

        printf("*");
        int m;
        m = (b - n) / 2;
        for (int i = 0; i < m - 1; i++)
            printf(" ");
        printf("%s", chr);
        m = b - n - m;
        for (int i = 0; i < m - 1; i++)
            printf(" ");
        printf("*");
        printf("\n");
        int c;
        c = a - k;
        k = 0;
        while (k < c - 3) {
            printf("*");
            for (int j = 0; j < b - 2; j++)
                printf(" ");
            printf("*");
            printf("\n");
            k++;
        }
        for (int i = 0; i < b; i++)
            printf("*");
    }
    else printf("Error");

    return 0;
}