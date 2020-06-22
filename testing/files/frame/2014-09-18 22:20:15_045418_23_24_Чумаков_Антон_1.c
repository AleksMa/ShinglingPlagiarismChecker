#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int height, width, i, j, x, k;
	x = 1;
	char word[100];
	if (argc != 4)
		printf ("Usage: frame <height> <width> <text>\n");
	else
	{
		height = atoi (argv[1]);
		width = atoi (argv[2]);
		strcpy (word, argv[3]);
		if (strlen (word) >= width - 1 || height < 3)
			printf ("Error\n");
		else
		{
			for (i = 0; i < width; ++i)
				putchar ('*');
			putchar ('\n');
			for (i = 2; i < height; ++i)
			{
				for (j = 0; j < width; ++j)
				{
					if (j == 0 || j == width - 1)
						putchar ('*');
					else
						putchar (' ');
					if (i == (height - 1) / 2 + 1 && j == (width - strlen (word)) / 2 - 1 && x == 1)
					{
						printf ("%s", word);
						j += strlen (word);
						x = 0;
					}
				}
				putchar ('\n');
			}
			for (i = 0; i < width; ++i)
				putchar ('*');
			putchar ('\n');
		}
	}	
	return 0;
}