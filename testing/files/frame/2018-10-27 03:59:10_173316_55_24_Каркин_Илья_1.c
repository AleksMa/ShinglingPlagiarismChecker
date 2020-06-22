#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        if (argc != 4)
	{
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int heigth = atoi(argv[1]);
	int width = atoi(argv[2]);
	int len = strlen(argv[3]);
	if (heigth < 3 || ((len + 2) > width))
	{
		printf("Error");
		return 0;
	}
	for (int i = 0; i < heigth; ++i)
		for (int j = 0; j < width; ++j)
		{
			if (j == (width - 1) && i != (heigth - 1))puts("*");
			else if (i == 0 || i == (heigth - 1) || j == 0)printf("*");
			else if (i == ((heigth - 1)/ 2) && j >= (width - len) / 2 && j < ((width - len) / 2 + len))
				printf("%c", argv[3][j - (width - len) / 2]);
			else printf(" ");
		}
	return 0;
}