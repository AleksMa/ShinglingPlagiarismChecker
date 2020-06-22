#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc!=4) printf("Usage: frame <height> <width> <text>\n");
        else {
                int n, i, k, h = atoi(argv[1]), w = atoi(argv[2]);
                n = strlen(argv[3]);
                if (w-2<n || h<3) {
                        printf("Error\n");
                } else {
                        for (i=0; i<w; i++) printf("*");
                        printf("\n");
                        for (i=1; i<h-1; i++) {
                                if (i==(h-1)/2) {
                                        printf("*");
                                        for (k=0; k<(w-n-2)/2; k++) printf(" ");
                                        printf("%s", argv[3]);
                                        for (k=0; k<(w-n-1)/2; k++) printf(" ");
                                        printf("*");
                                        } else {
                                                printf("*");
                                                for (k=0; k<w-2; k++) printf(" ");
                                                printf("*");
                                        }
                                        printf("\n");
                        }
                        for (k=0; k<w; k++) printf("*");
                        printf("\n");
                }
        }
        return 0;
}
