#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
        int height, width, i, j, k, n;
	height = 0;
	width = 0;
	if (argc != 4){
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	sscanf(argv[1], "%d", &height);
	sscanf(argv[2], "%d", &width);
	char* text = argv[3];
	i = 0;
	j = 0;
	k = 0;
	n = (height - 3) / 2;
	j = strlen((char*) text);
	if ((j > (width - 2)) || (height < 3)){
		printf("Error\n");
		return 0;
	}
	for (i = 0; i < (width - 1); i++)printf("*");//Верх
	printf("*\n");
	for (i = n; i > 0; i--){//Пустые строки в начале 
		printf("*");
		for (k = width - 2; k > 0; k--)printf(" ");
		printf("*\n");
	}
	printf("*");//Строка со словом 
	for (i = (width - 2 - j) / 2; i > 0; i--)printf(" ");
	for (i = 0; i < j; i++)printf("%c", text[i]);
	for (i = (width - 2 - j) / 2 + (width - 2 - j) % 2; i > 0; i--)printf(" ");
	printf("*\n");
	for (i = height - 3 - n; i > 0; i--){//Пустые строки в конце
		printf("*");
		for (k = width - 2; k > 0; k--)printf(" ");
		printf("*\n");
	}
	for (i = 0; i < width; i++)printf("*");//Низ
	return 0;
}