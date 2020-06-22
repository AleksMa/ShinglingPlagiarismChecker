#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int gc, char **gv)
{
        if (gc != 4)
	{
		printf("Usage: frame <height> <width> <text>\n");
	}
	else
	{
		int h1 = 0, p = 0, i = 0, j = 0;
		int  h = atoi(gv[1]), w = atoi(gv[2]);
		char* t = gv[3];
		if ((h < 3) || (strlen(t) >= w - 1))
			printf("Error\n");
		else
		{
			if (h % 2 == 0)
				h1 = h / 2;
			else h1 = (h / 2) + 1;
			for (i = 1; i <= h; i++)
			{
				if (1 == i)
				{
					for (j = 0; j < w; j++)
						printf("*");
					printf("\n");
				}
				if (h1 == i)
				{
					printf("*");
					for (p = 0;
                                        p < (w - 2 - strlen(t)) / 2;
                                        p++)
						printf(" ");
					printf("%s", t);
					for (p = 0;
                                        p < (w - 2 - strlen(t)) / 2; 
                                        p++)
						printf(" ");
					if ((w - 2 - strlen(t)) % 2 != 0)
						printf(" ");
					printf("*");
					printf("\n");
				}
				if ((h != i) && (h1 != i) && (1 != i))
				{
					printf("*");
					for (p = 0; p < w - 2; p++)
						printf(" ");
					printf("*");
					printf("\n");
				}
			}
			for (j = 0; j < w; j++)
				printf("*");
		}
	}
	return 0;
}