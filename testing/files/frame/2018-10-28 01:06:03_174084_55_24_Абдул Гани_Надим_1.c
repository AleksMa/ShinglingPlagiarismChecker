#include <stdio.h>
#include <string.h>

int strtoint(char* str)
{
	int l = strlen(str);
	int ans = 0;
	for (int i = 0; i < l; i++)
	{
		ans *= 10;
		ans += (str[i] - '0');
	}
	return ans;
}

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		int x = strtoint(argv[2]), y = strtoint(argv[1]), l = strlen(argv[3]);
		if ((x > l + 1) && (y > 2))
		{
			for (int i = 0; i < x; i++)
				printf("*");
			printf("\n");
			l = x - l - 2;
			for (int i = 2; i < y; i++)
			{
				if ((y + 1) / 2 == i)
				{
					printf("*");
					int j = 0;
					for (; j < l / 2; j++)
						printf(" ");
					printf("%s", argv[3]);
					for (; j < l; j++)
						printf(" ");
					printf("*\n");
				}
				else
				{
					printf("*");
					for (int j = 2; j < x; j++)
						printf(" ");
					printf("*\n");
				}
			}
			for (int i = 0; i < x; i++)
				printf("*");
		}
		else
			printf("Error");
	}
	else
		printf("Usage: frame <height> <width> <text>");
	return 0;
}