
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return -1;
    }
    unsigned long h = atoi(argv[1]);
    unsigned long w = atoi(argv[2]);
    char *str = argv[3];
    if (h<3 || w<strlen(str) + 2) {
        printf("Error");
        return -1;
    }
    for (int j = 0; j<h; j++) {
        if (j==0 || j==(h-1)) {
            for (int i = 0; i<(w); i++) {
                printf("*");
            }
            printf("\n");
        } else if ((((j == h/2 && j==1) || j == h/2-1) && h%2==0) || (j == h/2 && h%2)) {
            printf("*");
            unsigned long g = (w - strlen(str) - 2)/2;
            for (int i = 0; i<g; i++) {
                printf(" ");
            }
            printf("%s", str);
            for (int i = 0; i<(w - strlen(str) - 2 - g); i++) {
                printf(" ");
            }
            printf("*\n");
        } else {
            printf("*");
            for (int i = 0; i<(w-2); i++) {
                printf(" ");
            }
            printf("*\n");
        }
    }
    return 0;
}
 
