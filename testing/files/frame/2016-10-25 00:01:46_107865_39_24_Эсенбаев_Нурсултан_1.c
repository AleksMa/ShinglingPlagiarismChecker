#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw4(int w, char symbol, char *word)
{
        int i = 0;
	int len = strlen(word);
	for (i = 0; i < w; i++)
	{
		if (i == 0 || i == (w-1)) printf("%c", symbol);
		else
		{
			if (i == (w-2-len)/2 + 1)
			{
				printf("%s", word);
				if (w-2 == len)
				{
					printf("%c", symbol);
					break;
				}
				else i += len;
			}
			if (i != (w-1))	printf(" ");
		}
	}
	printf("\n");
}

void draw3 (int h, int w, char symbol)
{
	int i = 0;
	for (i = 0; i < w; i++)
	{
		if (i == 0 || i == (w-1)) printf("%c", symbol);
		else
		{
			printf(" ");
		}
	}
	printf("\n");
}

void draw2 (int h, int w, char symbol)
{
	int i = 0;
	for (i = 0; i < w; i++)	printf("%c", symbol);
	printf("\n");
}

void draw1 (int h, int w, char symbol, char *word)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		if (i == 0 || i == (h-1)) draw2(h, w, symbol);
		else
		{
			if ((h%2 == 0) && (i == (h/2 - 1)))
			{
				draw4(w, symbol, word);
				i +=1;
			}
			if ((h%2 != 0) && (i == (h-1)/2))
			{
				draw4(w, symbol, word);
			}
			else draw3(h, w, symbol);
		}
	}
}
 
int main(int argc, char **argv)
{
		if (argc != 4) 
		{
			printf("Usage: frame <height> <width> <text>\n"); 
			return 1; 
		}
		int h = atoi(argv[1]);
		int w = atoi(argv[2]);
		char *word = argv[3];

		int t = strlen(word);
		if ((t > (w - 2)) || ((h-2) < 1))
		{
			printf("Error\n");
			return 1;
		}
		else
		{
			draw1(h, w, '*', word);
		}
		return 0;
}