#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int a, b, midx, midy;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    if (atoi(argv[1]) < 3 || (atoi(argv[2]) - 2) < strlen(argv[3])) {
        printf("Error");
        return 0;
    }
    midx = (atoi(argv[2]) - strlen(argv[3])) / 2;
    midy = atoi(argv[1]) / 2;
    if (atoi(argv[1]) % 2) {
        midy++;
    }
    a = 0;
    while (a < atoi(argv[2])) {
        printf("*");
        a++;
    }
    printf("\n");
    b = 2;
    while (b < atoi(argv[1])) {
        a = 1;
        while (a < atoi(argv[2])) {
            if (a == 1) {
                printf("*");
            }
            if (a == atoi(argv[2]) - 1) {
                printf("*");
            }
            if (a >= midx && b == midy && a < midx + strlen(argv[3])) {
                printf("%c", argv[3][a - midx]);
            } else if (a != atoi(argv[2]) - 1 || a != 0) {
                printf(" ");
            }
            a++;
        }
        printf("\n");
        b++;
    }
    a = 0;
    while (a < atoi(argv[2])) {
        printf("*");
        a++;
    }
    printf("\n");
    return 0;
}