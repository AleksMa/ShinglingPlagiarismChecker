#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{        
	int i, h, d, n, m, j;
	
	if (argc == 4) {
		h=atoi(argv[1]) - 2; 
		d=atoi(argv[2]);
		n=strlen(argv[3]);
	
		if (n > d - 2 || h == 0) printf("Error\n");
		else {
			for (i = 0; i < d; printf("*"), i++);
			printf("\n");
			if (h % 2 == 0) m = h/2 - 1; 
			else m = h/2;
			for (i = 0; i < m; printf("*\n"), i++)
				for (printf("*"), j = 1; j < d - 1; printf(" "), j++); 
	
			if ((d - n) % 2 == 0) m = (d - n)/2 - 1; 
			else m = (d - n)/2;
	
			for (printf("*"), i = 1; i < (d - n)/2; printf(" "), i++); 
			for (printf("%s", argv[3]), i = 0; i < m; printf(" "), i++); 
			printf("*\n");
	
			for (i = 0; i < h/2; printf("*\n"), i++)
				for (printf("*"), j = 1; j < d - 1; printf(" "), j++); 
	
			for (i = 0; i < d; printf("*"), i++); printf("\n");
		}
	}
	else printf("Usage: frame <height> <width> <text> \n");
	return 0;
}