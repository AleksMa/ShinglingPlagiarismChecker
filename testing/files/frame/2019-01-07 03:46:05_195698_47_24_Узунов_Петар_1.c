#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc != 4)  {
                printf("Usage: frame <height> <width> <text>\n");
        }
        else {
            int i;
            int j;
            int k;
            int height;
            int width;
            char *text;
            int wordlen;
            text = argv[3];
            wordlen = strlen(text);
            height = atoi(argv[1]);
            width = atoi(argv[2]);
            int semi;
            int diff;
            int fdiff;
            int ctr;
            ctr = 0;
            diff = width - wordlen - 2;
            if (diff % 2 == 0){
                fdiff = diff / 2;
            }
            else {
                fdiff = (diff - 1) / 2;
            }
            if (height % 2 == 0){
                semi = height / 2;
            }
            else {
                semi = height / 2 + 1;
            }
            if (height <= 2){
                printf("Error");
            }
            else if (width <= 2){
                printf("Error");
            }
            else if (wordlen >= width - 1){
                printf("Error");
            }
            else {
                    for (i = 0; i < height; i++){
                        if ((i == 0) || (i == height - 1)){
                            for (j = 0; j < width; j++){
                                printf("*");
                            }
                            printf("\n");
                        }
                        else if (i == semi - 1){
                            for (j = 0; j < width; j++){
                                if (j == 0){
                                    printf("*");
                                }
                                if (j == width - 1){
                                    printf("*\n");
                                }
                                if ((j > 0) && (j <= fdiff)){
                                    printf(" ");
                                }
                                if ((j > (wordlen + fdiff)) && (j < width - 1)){
                                    printf(" ");
                                }
                                if ((j > fdiff) && (j <= (wordlen + fdiff))){
                                    printf("%c", text[ctr]);
                                    ctr++;
                                    }
                                }
                            }
                            else {
                                for (j = 0; j < width; j++){
                                    if (j == 0){
                                        printf("*");
                                    }
                                    else if (j == width - 1){
                                        printf("*\n");
                                    }
                                    else {
                                        printf(" ");
                                    }
                                }
                            }
                        }
                    }
                }
        return 0;
}
