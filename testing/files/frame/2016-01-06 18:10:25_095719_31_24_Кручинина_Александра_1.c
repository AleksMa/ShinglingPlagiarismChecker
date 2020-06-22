#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{    
    if  (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    char *slovechki = argv[3];
    int stroka, stolbec, k = strlen(slovechki);
    stroka = atoi(argv[1]);
    stolbec = atoi(argv[2]);
    if (k >= (stolbec-1) || stroka <= 2)
    {
        printf("Error");
        return 0;
    }
    int i, j, midSTR, midSTOLB;
    midSTR = ((stroka%2) == 0) ? ((stroka>>1) -1) : (stroka>>1);
    midSTOLB = (((stolbec - k) >> 1)-1);
    for (i = 0; i< stroka; i++)
    { for(j = 0; j < stolbec; j++)
        {
            if ((i == 0) || (i == stroka - 1))
                printf("*");
            if ((j == 0 || j == (stolbec - 1)) && (i!= 0) && (i != stroka -1) )
                printf("*");
            if ((i == midSTR) && (j == midSTOLB))
            {
                printf(slovechki);
                j += k;

            }
            if (i!= 0 && i !=stroka -1 && j!= (stolbec-2))
                printf(" ");
        }
        printf("\n");
   }
    return 0;
}