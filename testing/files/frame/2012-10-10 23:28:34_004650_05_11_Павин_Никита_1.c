
#include <stdio.h>
#include <string.h>

int main(int argc , char ** argv)
{
        int height, width, i, j, k, p;
        char text[100], *e, *o;
        if (argc < 3) {
		printf("usage: frame <height> <width> <text> \n") ;
		return 0;
	}
	height = strtol(argv[1], &e, 10);
	width = strtol(argv[2], &o, 10);
        p = strnlen(argv[3], 100) ;
        if ((height < 3) || (width < p + 2)) {
                printf("Error" "\n") ;
                return 0;
        }       
        for (i = 0; i < width; i++)
                printf("*");
	printf("\n");
	if (height % 2 == 1 && height != 3) {
	  printf("*");
	  for (i = 0; i < (width - 2); i++)
	    printf(" ");
	  printf("*\n");
	}
        for (i = 0; i < (height / 2 - 2); i++) {
                printf("*");
                for (j = 0; j < (width - 2); j++)
                        printf(" ");
                printf("*\n");
        }
        printf("*");
        k = (width - p - 2);           
        for (i = 0; i < (k / 2); i++)
        printf(" ");
        printf("%s", argv[3]);
        if (k % 2 == 1)
                k++;
        for (i = 0; i < (k / 2); i++)
                printf(" ");
        printf("*\n");
        for (i = 0; i < (height / 2 - 1); i++) {
                printf("*");
                for (j = 0; j < (width - 2); j++)
                        printf(" ");
                printf("*\n");
        }
        for (i = 0; i < width; i++)
                printf("*");
        printf("\n");
  return 0;
}