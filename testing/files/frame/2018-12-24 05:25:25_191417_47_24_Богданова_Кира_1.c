#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void helpToCheck(int *count, int a) {
    int counter = *count;
    if (a >= 0) {
        while (counter < 2*a) {
            counter++;
        }
    } else {
        while (counter > 2*a) {
            counter--;
        }
    }
    *count = counter;
}

int check(int a, int b) {
    swap(&a, &b);
    int counter1;
    int iter1;
    iter1 = counter1 = 0;
    helpToCheck(&counter1, a);
    helpToCheck(&iter1, b);
    swap(&counter1, &iter1);
    if (counter1 > iter1) {
        return 1;
    } else if (counter1 == iter1) {
        return 0;
    }
    return -1;
}

void connect(int *a, int b) {
    *a = b;
}

void print(int a){
    if (check(a, 0) == 0) { printf("*"); } 
    else if (check(a, 1) == 0) { printf(" "); }
}

int main(int argc, char **argv) {
    if (check(argc, 4) != 0)  { printf("Usage: frame <height> <width> <text>\n"); }
    else {        
        int a = atoi(argv[1]), b = atoi(argv[2]);
        char* s; s = argv[3];
        if ((b - 1 <= strlen(s)) || (check(a, 3) == -1)) { printf("Error\n"); }            
        else {
            int z;
            if (a % 2 == 0) { connect(&z, a / 2); }                
            else { connect(&z, a / 2 + 1); }
            for (int i = 1; i <= a; connect(&i, i + 1)) {
                if (check(i, 1) == 0) {
                    for (int j = 0; j < b; connect(&j, j + 1)) { print(0); }                        
                    printf("\n");
                }
                if (check(i, z) == 0) {
                    print(0); for (int j = 0; j < (b - 2 - strlen(s)) / 2; j++) { print(1); }                        
                    printf("%s", s); for (int q = 0; q < (b - 2 - strlen(s)) / 2; q++) { print(1); }                        
                    if ((b - 2 - strlen(s)) % 2 != 0) { print(1); }
                    print(0); printf("\n");
                }
                if ((i != 1) && (check(i, a) != 0) && (i != z)) {
                    print(0);  for (int j = 0; j < b - 2; j++) { printf(" "); }
                    print(0); printf("\n");
                }
            }
            for (int j = 0; j < b; j++) { print(0);; }                            
        }
    }
    return 0;
}