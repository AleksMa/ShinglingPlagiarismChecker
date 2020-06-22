#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
        int i, k, h, w, len = 0;
	const char *t;
	if(argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 1;
	}
	h = atoi(argv[1]);
	w = atoi(argv[2]);
	t = argv[3];
	while(t[len++]);
	len -= 1;
	if((w - len < 2) || (h < 3)) {
		printf("Error");
		return 2;
	}
	for(k = 0; k < w; k++) printf("*");
	printf("\n");
	for(i = 1; i < h - 1; i++) {
		if(i == (h / 2 - ((h % 2) ? 0 : 1))) {
			printf("*");
			for(k = 0; k < (w - len - 2) / 2; k++) printf(" ");
			printf("%s", t);
			for(k = 0; k < (w - len - 2) / 2 + (w - len) % 2; k++) printf(" ");
			printf("*");
		} else {
			printf("*");
			for(k = 1; k < w - 1; k++) {
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	for(k = 0; k < w; k++) printf("*");
	return 0;
}