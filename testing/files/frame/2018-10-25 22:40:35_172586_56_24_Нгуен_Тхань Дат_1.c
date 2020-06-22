#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_title_line(int length) {
    for (int i = 0; i < length; i++)
        printf("*");
    printf("\n");
}

void print_simple_line(int length) {
    printf("*");
        	for (int i = 1; i < length-1; i++) printf(" ");
		printf("*\n");
}

void center_text(const char *text, int width) {
    int length = strlen(text);
		int i;
    for (i = 0; i < (width - length) / 2; i++) {
        if (i == 0)
            printf("*");
        else
            printf(" ");
    }
    printf(text);
    i += length;
    for (; i < width; i++) {
        if (i == width-1)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char string[64] = { "\0" };
    int width = 0, length = 0;
    int centered_text_pos = 0;
    int strling_length = 0;

    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    strling_length = strlen(argv[3]);

    width  = atoi(argv[1]);
    length = atoi(argv[2]);
    strcpy(string, argv[3]);

		if (width < 3 || length-2 < strlen(string)) {
			printf("Error");
			return 0;
		}

    (width%2) ? (centered_text_pos = width / 2+1) : (centered_text_pos = width / 2);

    for (int counter = 1; counter <= width; counter++) {
        if (counter == 1 || counter == width)
            print_title_line(length);
        else if(counter == centered_text_pos)
            center_text(string, length);
        else
            print_simple_line(length);
    }

    return 0;
}
