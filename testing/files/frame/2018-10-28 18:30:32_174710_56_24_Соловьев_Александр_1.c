#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printChar(char ch, int n);
void firstLast(int width);
void noText(int width);
void textLine(int width, char * text);

void printChar(char ch, int n) {
        for (int i = 0; i != n; ++i)
		putc(ch, stdout);
}

void firstLast(int width) {
	printChar('*', width);
	puts("");
}

void noText(int width) {
	putc('*', stdout);
	printChar(' ', width - 2);
	putc('*', stdout);
	puts("");
}
void textLine(int width, char * text) {
	putc('*', stdout);
	int margins = width - 2 - strlen(text);
	int leftMargin = margins / 2;
	int rightMargin = margins - leftMargin;
	printChar(' ', leftMargin);
	printf("%s", text);
	printChar(' ', rightMargin);
	putc('*', stdout);
	puts("");
}

int main(int argc, char **argv) {
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 1;
	} 

	int height, width;
	char *text;

	text = argv[3];
	height = atoi(argv[1]);
	width = atoi(argv[2]);

	if (strlen(text) > width - 2 || height < 3) {
		printf("Error\n");
		return 1;
	}


	int mid = height % 2 == 0 ? height / 2 - 1 : height / 2;

	for (int i = 0; i != height; ++i) {
		if (i == 0 || i == height - 1) {
			firstLast(width);
		} else if (i == mid) {
			textLine(width, text);
		} else 
			noText(width);
	}



	return 0;
}
