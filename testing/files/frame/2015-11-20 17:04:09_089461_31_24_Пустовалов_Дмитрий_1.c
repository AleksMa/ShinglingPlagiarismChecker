#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_blank_line(int);
void print_frame(int, int, char*);

int main(int argc, char **argv)
{
        if (argc < 4) printf("Usage: frame <height> <width> <text>");
	else
	{
		int height = atoi(argv[1]);
		int width = atoi(argv[2]);
		if (height < 3 ||
			width < (int)strlen(argv[3]) + 2) printf("Error");
		else print_frame(height, width, argv[3]);
	}
	
	return 0;
}

void print_blank_line(int width)
{
	int i;
	printf("*");
	for (i = 2; i < width; ++i) printf(" ");
	printf("*\n");
}

void print_frame(int height, int width, char *text)
{
	int i;
	int margin_top = (height - 3) / 2;
	int margin_bottom = (height - 3) / 2 + (height - 3) % 2;
	int margin_left = (width - 2 - strlen(text)) / 2;
	int margin_right = (width - 2 - strlen(text)) / 2 + (width - 2 - strlen(text)) % 2;
	
	for (i = 0; i < width; ++i) printf("*");
	printf("\n");
	for (i = 0; i < margin_top; ++i) print_blank_line(width);
	
	printf("*");
	for (i = 0; i < margin_left; ++i) printf(" ");
	printf("%s", text);
	for (i = 0; i < margin_right; ++i) printf(" ");
	printf("*\n");
	
	for (i = 0; i < margin_bottom; ++i) print_blank_line(width);
	for (i = 0; i < width; ++i) printf("*");
	printf("\n");
}