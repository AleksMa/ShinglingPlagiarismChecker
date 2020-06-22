//
//  frame.c
//
//
//  Created by MacBook return 0; on 16.10.14.
//
//

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int h, l, i, j, string, nh, k, q;
    if (argc!=4) printf("Usage: frame <height> <width> <text>");
    else
    {
        h=atoi(argv[1]);
        l=atoi(argv[2]);
        if (h<3 || strlen(argv[3])>(l-2)) printf("Error");
        else {
            nh=h-1;
            for (i = 0; i < l; i++) {
                printf("*");
            }
            printf("\n");
            for (i = 1; i < nh; i++) {
                if (i==(nh/2)) {
                    printf("*");
                    for (j = 0; j < (l - strlen(argv[3]) - 2) / 2; j++) {
                        printf(" ");
                    }
                    printf("%s", argv[3]);
                    for (j = 0; j < (l - strlen(argv[3]) - 1) / 2; j++) {
                        printf(" ");
                    }
                    printf("*\n");
                } else {
                    printf("*");
                    for (q = 0; q < l - 2; q++) {
                        printf(" ");
                    }
                    printf("*\n");
                }
            }
            for (k = 0; k < l; k++) {
                printf("*");
            }
        }
    }
    return 0;
}