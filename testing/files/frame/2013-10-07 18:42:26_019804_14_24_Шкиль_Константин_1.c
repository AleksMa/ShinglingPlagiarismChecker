#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {
        int m, n, i, j;
        if (argc!=4) {
                printf ("Usage: frame <height> <width> <text>\n");
                return 0;
                }
        if (strnlen(argv[3], 128)>atoi(argv[2])-2 || atoi(argv[1])<3) {
                printf("Error");
                return 0;
                }
        m=(atoi(argv[1])+1)/2;
        n=(atoi(argv[2])-strnlen(argv[3], 128))/2+1;
        for (j=0; j<atoi(argv[2])-1; j++) printf("*");
        for (i=1; i<m-1; i++) {
                printf ("*\n*");
                for (j=1; j<atoi(argv[2])-1; j++) printf (" ");
        }
        printf("*\n*");
        for (j=1;j<n-1; j++) printf(" ");
        printf ("%s", argv[3]);
        for (j += strnlen(argv[3], 128); j<atoi(argv[2])-1; j++) printf(" ");
        for (i++; i<atoi(argv[1])-1; i++) {
                printf ("*\n*");
                for (j=1; j<atoi(argv[2])-1; j++) printf (" ");
        }
        printf("*\n*");
        for (j=1; j<atoi(argv[2]); j++) printf("*");
        return 0;
}