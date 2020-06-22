#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
    }
    else {
        if (strnlen(argv[3], 30) > atoi(argv[2])-2 || atoi(argv[1])<3) {
            printf("Error\n");
        }
        else {
            int str = ((atoi(argv[1])/2)/* - ((strnlen(argv[3], 30))/2)*/);
            if (atoi(argv[1])%2 == 0) str--;
            int st = ((atoi(argv[2])/2) - ((strnlen(argv[3], 30))/2));
            if (atoi(argv[2])%2 == 0) {
                st--;
                if (strnlen(argv[3], 30) % 2 == 0) st++;
            }
            for (int i = 0; i<atoi(argv[1]); i++){
                for (int j = 0; j<atoi(argv[2]); j++) {
                    if (i == str && j == st) {
                        printf("%s", argv[3]);
                        j += (strnlen(argv[3], 30)-1);
                    } else {
                        if (i == 0 || i == atoi(argv[1]) - 1) {
                            printf("*");
                        } else {
                            if (j == 0 || j == atoi(argv[2]) - 1) {
                                printf("*");
                            } else {
                                printf(" ");
                            }
                        }
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}