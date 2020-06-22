#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print_fill_line(int width) {
    int i;
    for (i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
}

void print_line(int width, const char *str) {
    int i;
    int l;
    int str_len = (int)strlen(str);
    
    l = (width - str_len) / 2;
    
    for (i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) {
            printf("*");
        }else{
            if (i >= l && i <= l+ str_len) {
                if (str[i-l]) {
                    printf("%c", str[i-l]);
                }else{
                    printf(" ");
                }
            }else{
                printf(" ");
            }
        }
    }
    printf("\n");
}

int main(int argc, char*argv[]) {
    
    int height;
    int width;
    int j;
    int n;
    int str_len;
    
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    
    str_len = (int)strlen(argv[3]);
    if (str_len > width - 2 || height <= 2) {
        printf("Error\n");
    }
    else {
        print_fill_line(width);
        n = ((height - 1) / 2) - 1;
        for (j = 0; j < height - 2; j++) {
            
            if (j == n || n < 0) {
                print_line(width, argv[3]);
            }
            else{
                print_line(width, "");
            }
        }
        print_fill_line(width);
    }
    
    
    
    
}