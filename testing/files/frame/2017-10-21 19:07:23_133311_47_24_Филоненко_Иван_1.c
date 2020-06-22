#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int i, j, len;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    len = strlen(argv[3]);
    if ((atoi(argv[1]) < 3) || (len > (atoi(argv[2]) - 2))) {
        printf("Error");
        return 0;
    }
    for (i = 0; i < atoi(argv[1]); i++) {
        for (j = 0; j < atoi(argv[2]); j++) {
            if (i == (atoi(argv[1])) / 2 - ((atoi(argv[1]) + 1) % 2)) {
                if (j == 0)
                    printf("*");
                else {
                    if ((j > 0) && (j <= ((atoi(argv[2]) - len - 2) / 2)))
                        printf(" ");
                    else {
                        if (j == (((atoi(argv[2]) - len - 2) / 2) + 1))
                            printf("%s", argv[3]);
                        else {
                            if ((j >= (((atoi(argv[2]) - len - 2) / 2) + 1 + len)) && (j < (atoi(argv[2]) - 1)))
                                printf(" ");
                            else if (j == (atoi(argv[2]) - 1))
                                printf("*\n");
                        }
                    }
                }
            } else {
                if ((i == 0) || (i == (atoi(argv[1]) - 1))) {
                    if (j == (atoi(argv[2]) - 1))
                        printf("*\n");
                    else printf("*");
                } else {
                    if (j == 0)
                        printf("*");
                    else {
                        if (j == (atoi(argv[2]) - 1))
                            printf("*\n");
                        else
                            printf(" ");
                    }
                }
            }
        }
    }
    return 0;
}