#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, j, l, h = atoi(argv[1]), d = atoi(argv[2]);
    char ind;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int dstr = strlen(argv[3]);
    if ((d-2 < dstr) || (h < 3)) {
        printf("Error");
        return 0;
    }
    for (i=0; i<d; i++)
        printf("*");
    printf("\n");
    h -= 2;
    if (h%2 == 1) {
        h >>= 1;
        ind = 1;
    }
    else {
        h = (h >>= 1) - 1;
        ind = 0;
    }
    for (i=0; i<h; i++) {
        printf("*");
        for (j=2; j<d; j++)
            printf(" ");
        printf("*\n");
    }
    printf("*");
    l = (d-2-dstr) >> 1;
    for (i=0; i<l; i++)
        printf(" ");
    printf("%s", argv[3]);
    for (i=-(d-dstr)%2; i<l; i++)
        printf(" ");
    printf("*\n");
    if ((h == 0) && (ind == 1)) {
        for (i=0; i<d; i++)
            printf("*");
        return 0;
    }
    if ((h == 0) && (ind == 0)) {
        printf("*");
        for (j=2; j<d; j++)
            printf(" ");
        printf("*\n");
        for (i=0; i<d; i++)
            printf("*");
        return 0;
    }
    for (i=(ind%2)-1; i<h; i++) {
        printf("*");
        for (j=2; j<d; j++)
            printf(" ");
        printf("*\n");
    }
    for (i=0; i<d; i++)
        printf("*");
    return 0;
}