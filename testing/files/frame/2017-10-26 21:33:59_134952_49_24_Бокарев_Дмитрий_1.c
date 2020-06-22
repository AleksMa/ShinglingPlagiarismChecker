#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc<4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int len, width;
    char *text;
    text = argv[3];
    width = atoi(argv[1]);
    len = atoi(argv[2]);
    int l=strlen(text);
    if ((l>len-2) || (width<3)) {printf("Error\n"); return 0;}
    int before = (len-2-l)/2;
    int after = len-2-before-l;
    for (int i=0; i<len; i++) printf("*"); printf("\n");
    for (int j=0; j<width-2; j++){
        printf("*");
        if (width % 2==0) {
            if (j == (width - 2) / 2-1) {
                for (int k = 0; k < before; k++) printf(" ");
                printf("%s", text);
                for (int k = 0; k < after; k++) printf(" ");
            } else for (int i = 1; i < len - 1; i++) printf(" ");
        }
        if (width % 2!=0) {
            if (j == (width - 2) / 2) {
                for (int k = 0; k < before; k++) printf(" ");
                printf("%s", text);
                for (int k = 0; k < after; k++) printf(" ");
            } else for (int i = 1; i < len - 1; i++) printf(" ");
        }
        printf("*");
        printf("\n");
    }

    for (int i=0; i<len; i++) printf("*"); printf("\n");
    return 0;
}