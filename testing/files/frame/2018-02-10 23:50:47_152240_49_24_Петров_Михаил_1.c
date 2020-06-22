#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , char **argv)
{
    int a = 0,b = 0;
    char *s = argv[3];
    if (argc < 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    a += atoi(argv[1]);
    b += atoi(argv[2]);
    int c = strlen(s) - 1;
    int d = b - c;
    if (b == 0) {
        printf("Error");
        return 0;
    }
    if (a < 3){
        printf("Error");
        return 0;
    }
    if (c >= b - 2){
        printf("Error");
        return 0;
    }
        for (int i = 0; i < b; i++)
            printf("*");
    printf("\n");
    if (a%2 == 0) {
        for (int i = 0; i < (a / 2 - 1) - 1; i++) {
            printf("*");
            for (int j = 2; j < b; j++)
                printf(" ");
            printf("*\n");
        }
    } else {
        for (int i = 0; i < (a / 2) - 1; i++) {
            printf("*");
            for (int j = 2; j < b; j++)
                printf(" ");
            printf("*\n");
        }
    }
        printf ("*");
    if (d%2 == 0) {
        for (int i = 0; i < (d / 2) - 2; i++)
            printf(" ");
        printf("%s", s);
        for (int i = 0; i < (d - (d / 2)) - 1; i++)
            printf(" ");
        printf("*\n");
    } else {
        for (int i = 0; i < (d / 2) - 1; i++)
            printf(" ");
        printf("%s", s);
        for (int i = 0; i < (d / 2) - 1; i++)
            printf(" ");
        printf("*\n");
    }
        for (int i = 0; i < (a/2-1);i++){
            printf("*");
            for (int j = 2; j < b; j++)
                printf(" ");
            printf("*\n");
        }
        for (int i = 0; i < b; i++)
            printf("*");
    return 0;


}