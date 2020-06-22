#include <stdio.h>

void print_starline(int width) {
        int i;
	for (i = 0; i < width - 1; i++)
		printf("*");
	puts("*");
}

void print_emptyline(int height, int width) {
	int i, j;
	for (i = 0; i < height; i++) {
		printf("*");
		for (j = 0; j < width; j++)
			printf(" ");
		puts("*");
	}
}

int main(int argc, char **argv) {
	int i, part1, part2, size, pre, post, height, width;
	char symb[100];
	if (argc != 4) {
		puts("Usage: frame <height> <width> <text>");
		return 0;
	}
	strcpy(symb, argv[3]);
	size = strlen(symb);
	width = atoi(argv[2]) - 2;
	if (size > width || atoi(argv[1]) < 3) {
		puts("Error");
		return 0;
	}
	height = atoi(argv[1]) - 2;
	part2 = height / 2;
	post = width / 2 + width % 2 - size / 2;
	if (size == 1)
		post -= 1;
	part1 = height - part2 - 1;
	pre = width - post - size;
	print_starline(atoi(argv[2]));
	print_emptyline(part1, width);
	printf("*");
	for (i = 0; i < pre; i++)
		printf(" ");
	printf("%s", symb);
	for (i = 0; i < post; i++)
		printf(" ");
	puts("*");
	print_emptyline(part2, width);
	print_starline(atoi(argv[2]));
}