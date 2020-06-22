#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	
	int height = atoi(argv[1]),
		width  = atoi(argv[2]),
		n = strlen(argv[3]),
		i, k, textY = height / 2, textX = (width - n)/2 + 1;

	if (height % 2) textY++;
	
	if ((n > width - 2) || (height <= 2)) {
		printf("Error\n");
		return 0;
	}
	
	for (i = 1; i < height + 1; i++) {
		for (k = 1; k < width + 1; k++) {
			if ((i == 1) || (i == height) || 
			    (k == 1) || (k == width)) printf("*");
			else {
				if (i != textY) printf(" ");
				else {
					if ((k < textX) || (k - n >= textX)) printf(" ");
					else {
						printf("%c", argv[3][k - textX]);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}