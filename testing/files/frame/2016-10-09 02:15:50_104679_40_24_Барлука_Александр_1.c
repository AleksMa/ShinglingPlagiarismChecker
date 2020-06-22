#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc != 4) 
	{
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	}
	
	char h = atoi(argv[1]);
	char w = atoi(argv[2]);
	char *t = argv[3];

	if ((strlen(t) > w-2) || (h < 3))
	{
		printf("Error\n");
		return -1;
	}
	
	for (int i = 0; i < h; i++)
	{
		if (i == 0 || i == h-1)
		{
			for (int j = 0; j < w; j++) printf("*");
			printf("\n");
		}
		else
		{
			printf("*");
			if (i == (h-1)/2)
			{
				for (int j = 0; j < w-1; j++)
				{
					if (j == (w-2-strlen(t))/2)
					{
						printf("%s" , t);
						j += strlen(t);
					}
					else
					{
						printf(" ");
					}
				}
				printf("*");
				printf("\n");
			}
			else
			{
				for (int j = 0; j < w-2; j++) printf(" ");
				printf("*");
				printf("\n");
			}
		}
	}
	return 0;
}