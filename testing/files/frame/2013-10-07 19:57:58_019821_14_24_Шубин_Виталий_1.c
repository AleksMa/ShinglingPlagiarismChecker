#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void charout(int count, char c)
{
        while (count--)
		putchar(c);
}

int main(int argc, char **argv)
{
	int width, height, res = 0, tlen, spaces;
	char *text, *outbuff;
	text = (char *)calloc(1024, sizeof(char));

	if(argc == 4)
	{
		res += sscanf(argv[1], "%d", &height);
		res += sscanf(argv[2], "%d", &width);
		res += sscanf(argv[3], "%s", text);
	}

	if(res != 3)
	{
		free(text);
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	tlen = strlen(text);
	if(width - 2 < tlen || height < 3)
	{
		free(text);
		printf("Error\n");
		return 0;
	}

	charout(width, '*');
	putchar('\n');
	spaces = (height - 3)/2;

	while (spaces--)
	{
		putchar('*');
		charout(width-2, ' ');
		putchar('*');
		putchar('\n');
	}
	putchar('*');
	spaces = (width - 2 - tlen)/2;
	charout(spaces, ' ');
	printf("%s", text);
	spaces = (width - 2 - tlen) - spaces;
	charout(spaces, ' ');
	putchar('*'); putchar('\n');

	spaces = (height - 3) - (height - 3)/2;

	while (spaces--)
	{
		putchar('*');
		charout(width-2, ' ');
		putchar('*');
		putchar('\n');
	}

	charout(width, '*');
	free(text);
	return 0;
}
//дублирование кода - наше все..