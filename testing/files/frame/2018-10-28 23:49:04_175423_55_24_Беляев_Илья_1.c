#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ramka(int height, int width, char* text) {
    int length = strlen(text);
    if (width < length + 2) {
        printf("%s", "Error");
        return;
    }

    if (height < 3) {
        printf("%s" , "Error");
        return;
    }

    int j = 1 + (height - 3) / 2;

    for (int k = 0; k < height; k++) {
        if (k == 0 || k == (height - 1))
            for (int zvezda = 0; zvezda < width; zvezda++)
                printf("%s" , "*");

        else {

            printf("%s", "*");
            int len_spaces = (width - 2 - length) / 2;

            for (int space = 0; space < len_spaces; space++)
                printf("%s", " ");

            if (k == j)
                printf("%s", text);
            else
                for (int space = 0; space < length ; space++)
                    printf("%s" , " ");

            for (int space = 0; space < width - 2 - length - len_spaces ; space++)
                printf("%s" , " ");

            printf("%s" , "*");

        }
        printf("%s" , "\n");

    }

}


int main(int argc, char* argv[]){

    int n = argc;

    if (n != 4) {
        printf("%s" , "Usage: frame <height> <width> <text>");
        return 0;
    }
    int height = atoi(argv[1]);
    int width = atoi(argv[2]); 

    print_ramka(height, width, argv[3]);

    return 0;
}