
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void upl(int width) {
    scanf("%d", &width);
    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
}

void empty(int width, int height) {
    int i, j, middle;
    if (height % 2 == 0) {
        middle = (height % 2);
    } else {
        middle = ((height % 2) - 1);
    }
    for (i = 0; i <= middle; i++) {
        printf("*");
        for (j = 0; j < width-2; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
}

void text_ct(int width, char *text) {
    unsigned long i, n;
    unsigned long sl;
    sl = strlen(text);
    n = ((width - sl) / 2);
    printf("*");
    if ((width % 2 != 0) && (sl % 2 == 0)) {
        for (i = 0; i < n - 1 ; i++) {
            printf(" ");
        }
    } else {
        for (i = 0; i < n-1; i++) {
            printf(" ");
            
        }
    }
    printf("%s", text);
    if ((width - sl) % 2 != 0) {
        for (i = 0; i < n; i++) {
            printf(" ");
        }
    } else {
        for (i = 0; i < n - 1; i++) {
            printf(" ");
        }
    }
    printf("*");
    printf("\n");
}

int main (int argc, char *argv[]) {
    char text[64] = {"\0"};
    int width = 0, height = 0;
    int schet = 0, mid_txt = 0;
    unsigned long txt_length = 0;
    
    
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    height  = atoi(argv[1]);
    width = atoi(argv[2]);
    strcpy(text, argv[3]);
    
    txt_length = strlen(argv[3]);
    
    if ((width-2 < txt_length) || (height <= 2)) {
        printf("Error");
        return 0;
    }
    
    if (height % 2) {
        mid_txt = (height/2) + 1;
    } else {
        mid_txt = (height/2);
    }
    
    for (schet = 1; schet <= height; schet++) {
        if (schet == 1 || schet == height) {
            upl(width);
        } else {
            if (schet == mid_txt) {
                text_ct(width, text);
            } else {
                empty(width, height);
            }
        }
        
    }
    return 0;
}
