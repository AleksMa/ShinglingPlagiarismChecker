#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {
    if (argc!=4) {
        printf ("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int i, j, height = atoi(argv[1]), width = atoi(argv[2]);
    if (((int)strlen(argv[3])>width-2)||(height<3)) {
        printf("Error\n");
        return 0;
    }
    char a[height][width+1];
    for (i = 0; i<width; ++i) a[height-1][i] = a[0][i] = '*';
    a[0][width] = a[height-1][width] = '\0';
    for (i = 1; i<(height-1); ++i) {
        for (j = 0; j<width; ++j) a[i][j] = ' ';
        a[i][width] = '\0';
        a[i][0] = a[i][width-1] = '*';
    }
    strncpy(&a[(height-1)/2][(width-strlen(argv[3]))/2], argv[3], strlen(argv[3]));
    for (i = 0; i<height; ++i) printf ("%s\n", a[i]);
    return 0;
}