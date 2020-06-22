#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int i, j, a, b, c, d;
        int he = atoi(argv[1]);
	int wid = atoi(argv[2]);
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int len = strlen(argv[3]);
	if ((wid - 2 < len) || (he < 3)) { 
		printf("Error\n");
		return 0;
	}
	for (i = 0; i < wid; i++) printf("*"); /* верхняя грань */ 
	printf("\n");
	a = (he - 3) / 2;
	b = he - (a + 3);
	c = (wid - (len + 2)) / 2;
	d = wid - (len + 2 + c);
	for (i = 0; i < a; i++) { /* часть рамки ДО надписи */
		printf("*");
		for (j = 0; j < (wid - 2); j++) printf(" ");
		printf("*");
		printf("\n");
	}
	{ /* строка с надписью */
		printf("*");
		for (i = 0; i < c; i++) printf(" ");
		printf("%s", argv[3]);
		for (i = 0; i < d; i++) printf(" ");
		printf("*");
		printf("\n");
	}
	for (i = 0; i < b; i++) { /* часть рамки ПОСЛЕ надписи */
		printf("*");
		for (j = 0; j < (wid - 2); j++) printf(" ");
		printf("*");
		printf("\n");
	}	
	for (i = 0; i < wid; i++) printf("*"); /* нижняя грань */
	printf("\n");
	return 0;
} 

