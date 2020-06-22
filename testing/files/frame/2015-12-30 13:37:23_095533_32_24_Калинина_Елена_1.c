
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef char* String;
 
int main(int argc, char **argv)
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	String string = argv[3];
	int height, width, length, i, j;
	height = atoi(argv[1]);
	width = atoi(argv[2]);
	length = strlen(string);
	if (height < 3 || length > width-2) {
		printf("Error\n");
		return 0;
	}
	int margins[] = { (height - 1) / 2, (width - length) / 2 };
	for (i = 0; i < height; i++) {
		printf("*");
		for (j = 1; j < width - 1; j++) {
			if ((i == margins[0]) && (j == margins[1])) {
				String p;
				for (p = string; *p != '\0'; p++) putchar(*p);
				j = j+length-1;
				continue;
			}
			if ((i == 0) || (i == height-1)) putchar('*');
			else putchar(' ');
		}
		printf("*");
		printf("\n");
	}
    return 0;
}