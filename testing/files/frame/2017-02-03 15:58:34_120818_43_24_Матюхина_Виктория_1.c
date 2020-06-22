#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 4) printf("Usage: frame <height> <width> <text>\n");
    else if(strlen(argv[3]) > atoi(argv[2]) - 2 || atoi(argv[1]) < 3) printf("Error\n");
    else {

        int x, y;
        y = (atoi(argv[1]) + 1) / 2;
        if(strlen(argv[3]) > 1) x = (atoi(argv[2])) / 2 - (strlen(argv[3]) + 1) / 2;
        else x = (atoi(argv[2])) / 2 - (strlen(argv[3])) / 2;

        char st[atoi(argv[2])];
        for(int i = 0; i < atoi(argv[1]); i++) {
            if(i == 0 || i == (atoi(argv[1]) - 1)) {
                for(int j = 0; j < atoi(argv[2]); j++) printf("*");
                printf("\n");
            }
            else if(i == y - 1) {
                printf("*");
                for(int j = 1; j < x; j++) printf(" ");
                printf("%s", argv[3]);
                for(int j = x + strlen(argv[3]) + 1; j < atoi(argv[2]); j++) printf(" ");
                printf("*\n");
            }
            else {
                printf("*");
                for(int j = 1; j < atoi(argv[2]) - 1; j++) printf(" ");
                printf("*\n");
            }
        }
    }

    return 0;
}