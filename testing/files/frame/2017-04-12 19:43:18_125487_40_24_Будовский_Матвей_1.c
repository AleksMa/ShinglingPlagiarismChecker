#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
    int x = 0, y = 2;
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    else if (atoi(argv[1]) < 3 || (atoi(argv[2]) - 2) < strlen(argv[3])){
        printf("Error\n");
        return 0;
    }
    int midd1 = (atoi(argv[2]) - strlen(argv[3])) / 2;
    int midd2 = atoi(argv[1]) / 2;
    if (atoi(argv[1]) % 2) { midd2 += 1; }
    while (x < atoi(argv[2])) {
        printf("*");
        x += 1;
        }
    printf("\n");
    while (y < atoi(argv[1])){
        x = 1;
        while (x < atoi(argv[2])){
            if (x == 1) { printf("*"); }
            if (x == atoi(argv[2]) - 1) { printf("*"); }
            if (x >= midd1 && y == midd2 && x < midd1 + strlen(argv[3])) { printf("%c", argv[3][x - midd1]); }
            else if (x != atoi(argv[2]) - 1 || x != 0) { printf(" "); }
            x += 1;
        }
        y += 1;
        printf("\n");
    }
    x = 0;
    while (x < atoi(argv[2])) {
        printf("*");
        x += 1;
    }
    return 0;
} 
