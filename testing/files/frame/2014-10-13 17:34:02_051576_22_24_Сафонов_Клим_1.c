#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
        
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
	} else {
		int height, width, length, height_start = 0, width_start;
		char *text;
		
		height = atoi(argv[1]);
		width = atoi(argv[2]);
		text = argv[3];
		length = strlen(text);
		/* 
		printf("Height %d\n", height);
		printf("Width %d\n", width);
		printf("Text %s\n", text);
		printf("Length of text %d\n", length);
		*/
		if ((length >= width) || (height <= 2) || ((length + 2) > width)) {
			printf("Error\n");
			return 0;
		} else {
			int print_left = (width - length - 2) / 2, print_up = (height - 2) / 2;
			
			if ((height % 2) != 0) {
				print_up++;
			}
			for (height_start; height_start < height; height_start++) {
				for (width_start = 0; width_start < width; width_start++) {
					/* Печать первой и последней строки */
					if ((width_start > 0) && (width_start < (width - 1)) && ((height_start == 0) || (height_start == (height - 1)))) {
						printf("*");
					}
					/* Печать первого и последнего столбца */
					if (width_start == 0) {
						printf("*");
					}
					if (width_start == (width - 1)) {
						printf("*\n");
					}
					/* Печать слова (text) */
					if ((height_start == print_up) && (width_start == print_left)) {
						printf("%s", text);
					}
					/* Печать пробелов для всех строк кроме содержащей текст */
					if ((width_start > 0) && (width_start < (width - 1)) && (height_start > 0) && (height_start < (height - 1)) && (height_start != print_up)) {
						printf(" ");
					}
					/* Печать пробелов для строки содержащей текст */
					if ((height_start == print_up) && (width_start < (width - 1))&& ((width_start < print_left) || (width_start > (print_left + length)))) {
						printf(" ");
					}
				}
			}
		}
	}
	return 0;
}
