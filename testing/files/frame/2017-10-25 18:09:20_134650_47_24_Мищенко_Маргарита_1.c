#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc != 4)  {
                printf("Usage: frame <height> <width> <text>\n"); 
        } 
        else { 
                int i = 0, j = 0, k = 0, o = 0;
                int dlina = atoi(argv[1]), shirina = atoi(argv[2]);
                char* s;
                s = argv[3];
                if ((shirina - 1 <= strlen(s)) || (dlina < 3))
                        printf("Error\n"); 
                else {
                        if (dlina % 2 == 0)
                        k = dlina / 2;
                        else k = dlina / 2 + 1;
                        for (i = 1; i <= dlina; i++) { 
                                if (i == 1) {
                                        for (j = 0; j < shirina; j++)
                                                printf("*");
                                                printf("\n");
                                        }
                                if (i == k) {
                                        printf("*");
                                        for (o = 0; o < (shirina - 2 - strlen(s)) / 2; o++)
                                                printf(" ");
                                        printf("%s", s);
                                        for (o = 0; o < (shirina - 2 - strlen(s)) / 2; o++)
                                                printf(" ");
                                        if ((shirina - 2 - strlen(s)) % 2 != 0)
                                                printf(" ");
                                        printf("*");
                                        printf("\n");
                                }
                                if ((i != 1) && (i != dlina) && (i != k)) {
                                        printf("*");
                                        for (o = 0; o < shirina - 2; o++)
                                                printf(" ");	
                                        printf("*");
                                        printf("\n");	
                                }
                        }
                        for (j = 0; j < shirina; j++)
                                printf("*");
                }
        }
        return 0;
}