#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sumbol(char c, int count){
    for (int i = 0; i < count; ++i) {
        printf("%c",c);
    }
}

void Tabl(int w, int h, char *word) {
    print_sumbol('*',w); printf("\n");
    for (int j = 0; j < h - 2; j++) {
        printf("*");
        if(j == (h - 2) / 2 - (1 - (h - 2) % 2)){
            int d = (w - strlen(word) - 2) / 2;
            int dd = (strlen(word) % 2) ^ (w % 2);
            print_sumbol(' ',d);
            printf("%s",word);
            print_sumbol(' ',d + dd);
        }else{
            print_sumbol(' ',w - 2);
        }
        printf("*\n");
    }
    print_sumbol('*',w);
}

int main(int argc, char **argv) {
    int w=atoi(argv[2]), h=atoi(argv[1]);
    if (argc != 4) {
        printf ("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    else {
        if (h < 3 || (strlen(argv[3]) > w - 2)){
            printf("Error");
        } else {
            Tabl(w, h, argv[3]);
            printf ("\n");
        }
        return 0;
    }
}