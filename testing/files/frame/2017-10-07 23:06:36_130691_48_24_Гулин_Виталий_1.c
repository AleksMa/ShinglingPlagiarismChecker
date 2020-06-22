#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTL 512

int main(int argc, char const *argv[]) {
        int width, height, s_len;

	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	} else {
		width = atoi(argv[2]);
		height = atoi(argv[1]);
		s_len = strnlen(argv[3], MAXTL);
	}

	if(strlen(argv[3]) > (width - 2) || height <= 2) {
		printf("Error\n");
		return -1;
	}

	for (int i = 1; i <= height; i++) {
		for (int j = 1, k = 0; j <= width; j++) {
			if (i == 1 || i == height || j == 1 || j == width) {
				printf("%c", '*');
			} else if (i == (height + 1) / 2 && k < s_len && j <= (width + s_len) / 2 && j >= (width - s_len + 2) / 2) {
				printf("%c", argv[3][k++]);
			} else {
				printf("%c", ' ');
			}
		}
		printf("\n");
	}

	return 0;
}