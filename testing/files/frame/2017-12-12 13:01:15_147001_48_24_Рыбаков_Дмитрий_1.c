#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int a = atoi(argv[1]),
            b = atoi(argv[2]),
            m = a/2,
            j = 0,
            i = 0;
    if ((argv[1] == 0) || (argv[2] == 0) || (argv[3] == 0))
        printf("Usage: frame <height> <width> <text>");
    else {
        int lens = strlen(argv[3]);
        if ((b < lens + 2) || (a < 3))
            printf("Error");
        else {
            for (i = 0; i < b; i++) {
                putchar('*');
            }
            printf("\n");
            for (i = 0; i < a - 2; i++) {
                putchar('*');
                if (((i == m - 1) && (a%2 == 1)) || ((i == m - 2) && (a%2 == 0)) || (a == 3)) {
                    for (j = 0; j < ((b - lens) / 2 - 1); j++)
                        putchar(' ');
                    printf("%s", argv[3]);
                    for (;j+lens < b-2;j++)
                        putchar(' ');
                    putchar('*');
                    printf("\n");
                } else {
                    for (int p = 1; p < b - 1; p++)
                        putchar(' ');
                    putchar('*');
                    printf("\n");
                }
            }
            for (int i = 0; i < b; i++) {
                putchar('*');
            }
        }
    }
    return 0;
}