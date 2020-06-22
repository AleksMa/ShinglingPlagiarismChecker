#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc!= 4) {
		printf ("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	unsigned long p = (atoi(argv[2])-2), q = strlen(argv[3]);
	if ((atoi (argv[1]) < 3) || (p < q)) printf ("Error\n");
	else {
		int height = atoi(argv[1]), width = atoi(argv[2]);
		int i = 0, j = 0, k =0;
		for (i = 0; i < width; i++) printf("*");
		printf("\n");
		for (j = 1; j< height-1; j++) {
			printf("*");
			if (j==((height+1)/2)-1) {
				k = (width-2-q)/2;
				for (i = 0; i<k; i++) printf(" ");
				printf("%s", argv[3]);
				for (i=(width-q)/2+q;i<width-1;i++) printf(" ");
			}
			else {
				for (i=0; i<width-2; i++) printf(" ");
			}
			printf("*\n");
		}
	for (i = 0; i < width; i++) printf("*");
	printf("\n");
	return 0;
	}
}