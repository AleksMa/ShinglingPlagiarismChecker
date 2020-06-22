#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *usage = "Usage: frame <height> <width> <text>";
const char *error = "Error";

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("%s\n", usage);
        return 0;
    }
    
    char *string = argv[3];
    int height = atoi(argv[1]), width = atoi(argv[2]);
    int length = strlen(string);
    
    if (height < 3 || length > width - 2) {
        printf("%s\n", error);
        return 0;
    }
    
    int margins[] = { (height - 1) / 2, (width - length) / 2 };
       
    for (int i = 0; i < height; i++) {
        putchar('*');
        for (int j = 1; j < width - 1; j++) {
            if (i == margins[0] && j == margins[1]) {
                for (char *p = string; *p != '\0'; p++) {
                    putchar(*p);
                }
                j += length - 1;
                continue;
            }
            
            if (i == 0 || i == height - 1) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('*');
        putchar('\n');
    }
    
    return 0;
}