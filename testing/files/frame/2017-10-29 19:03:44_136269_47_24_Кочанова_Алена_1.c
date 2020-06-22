#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int height, width, i, j, nel,text_col = 0, text_row = 0;
    if(argc!=4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    nel = strlen(argv[3]);
    text_col = (width - nel)/2;
    text_row = (height-1)/2;
    if((nel>(width-2))||(height<3)) {
        printf("Error");
        return -1;
    }
    for (i=0;i<width;i++) {
        printf("*");
    }
    printf("\n");
    for(i=1;i<height-1;i++) {
        printf("*");
        if(i==text_row) {
            for(j=1;j<text_col;j++) {
                printf(" ");
            }
            printf("%s",argv[3]);
            for(j=text_col + nel;j<width-1;j++) {
                printf(" ");
            }
        }
        else {
            for(j=0;j<width-2;j++) {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for(i=0;i<width;i++) {
        printf("*");
    }
    printf("\n");
    return 0;
}