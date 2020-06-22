#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 4) printf ("Usage: frame <height> <width> <text>\n");
    else {
        int a = atoi (argv [1]), b = atoi (argv [2]), d = 0;
        d = strlen (argv [3]);
        
        int i = 1, k = b; /*i=1, поскольку при i=0 первым символом будет пробел*/
        int j; /*j - середина рамки, там будет строка*/
        if (a % 2 == 1) j = (a / 2) + 1; /*Определяем середину рамки*/
        else j = a / 2;
        int left, right; /*Символы до и после строки*/
        if ((b - d) % 2 == 1) {
            left = (b - d) / 2;
            right = ((b - d) / 2) + 1; 
        }
        else left = right = (b - d) / 2;
        
        if ((d <= (b - 2)) && (a>2) && (b>2)) {    /*Поместится ли строка в рамку?*/
            for (; i <= a; ++i) {
                if ((i == 1) | (i == a)) {
                    while (k>0) {
                        printf ("*");
                        k = k - 1;
                    }
                    if (i == 1) printf ("\n");
                    k = b;
                }
                
                else if (i == j) {       /*Работаем со строкой и рамкой*/
                    k = 1;
                    while (k <= left) {
                        if (k == 1) printf ("*");
                        else printf (" ");
                        k = k + 1;
                    }
                        printf ("%s", argv [3]);
                        k = k + d;
                    while (k <= b) {
                        if (k != b) printf (" ");
                        else printf ("*\n");
                        k = k + 1;
                    }
                    j = i - 1;
                    k = b;
                }
                
                else {
                    while (k>0) {
                        if ((k == b) | (k == 1)) printf ("*");
                        else printf (" ");
                        k = k - 1;
                    }
                    printf ("\n");
                    k = b;
                }
            }
        }
        else printf ("Error\n");
    }
    return 0;
}