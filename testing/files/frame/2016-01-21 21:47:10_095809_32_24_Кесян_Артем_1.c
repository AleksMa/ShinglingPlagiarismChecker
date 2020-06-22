#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int width, height;
	height = atoi(argv[1]);
	if (height < 3) {
		printf("Error");
		return 0;
	}
	width = atoi(argv[2]);
	char *text = argv[3];
	int len = strlen(text);
	if (len + 2 > width) {
		printf("Error");
		return 0;
	}
	int text_h = (height - 1) / 2;
	int text_w = (width - len) / 2;
	char top[width + 1], mid[width + 1], txt[width + 1];
	memset(top, '*', width);
	top[width] = '\0';
	memset(mid, ' ', width);
	mid[0] = mid[width - 1] = '*';
	mid[width] = '\0';
	memcpy(txt, mid, width + 1);
	memcpy(txt + text_w, text, len);
	printf("%s\n", top);
	for (int i = 1; i < text_h; i++)
		printf("%s\n", mid);
	printf("%s\n", txt);
	for (int i = text_h + 1; i < height - 1; i++)
		printf("%s\n", mid);
	printf("%s", top);
}