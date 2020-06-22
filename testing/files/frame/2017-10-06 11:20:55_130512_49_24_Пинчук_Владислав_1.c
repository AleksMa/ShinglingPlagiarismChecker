#include <stdio.h>

void horizontal_line(int width);
void edges(int width, char *str, int s_size);

int main(int argc, char **argv)
{
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int height = atoi(argv[1]),width = atoi(argv[2]);
    char *s = argv[3];

    int s_size = 0;
    while (s[s_size]) ++s_size;

    if (s_size>width-2 || height-2<1) {
        printf("Error");
        return 0;
    }

    int dist_w = (width-2-s_size)/2, dist_h = (height-3)/2;

    horizontal_line(width);
    int iter = 0;
    while (iter<dist_h) {
        edges(width,"",0);
        ++iter;
    }
    edges(width,s,s_size);
    iter = 0;
    while (iter<height-3-dist_h) {
        edges(width,"",0);
        ++iter;
    }
    horizontal_line(width);


    return 0;
}

void horizontal_line(int width) {
    for (int i=0;i<width;++i) {
        printf("*");
    }
    printf("\n");
}
void edges(int width, char *str, int s_size) {
    printf("*");
    int i,dist=(width-2-s_size)/2;
    for (i=0;i<dist;++i) {
        printf(" ");
    }
    for (i=0;i<s_size;++i) {
        printf("%c",str[i]);
    }
    for (i=0;i<width-2-dist-s_size;++i) {
        printf(" ");
    }
    printf("*\n");
}
