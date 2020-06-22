#include <stdio.h>
 
int main(int argc, char **argv)
{
        if (argc != 4){
		printf("Usage: frame <height> <width> <text>");
                return 0;
        }
	char *m;
	m = *(argv + 3);
	int i;
	int j;
	int width = atoi(*(argv + 2));
	int height = atoi(*(argv + 1));
	
	if (strnlen(m, 500) > width - 2 || height < 3){
		printf("Error");
		return 0;
	}

	for (i = 0; i < width; i++)
		printf("*");
	printf("\n");
	for (i = 0; i < (height - 3) / 2; i++){
		printf("*");
		for (j = 0; j < (width - 2); j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	
	printf("*");
	for (j = 0; j < ((width - 2) - strnlen(m, 500)) / 2; j++)
		printf(" ");
	i = 0;
	while (m[i]){
		printf("%c", m[i]);
		i++;
	}
	for (j = 0; j < ((width - 1) - strnlen(m, 500)) / 2; j++)
		printf(" ");
	printf("*");
	printf("\n");
	for (i = 0; i < (height - 2) / 2; i++){
		printf("*");
		for (j = 0; j < (width - 2); j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	for (i = 0; i < width; i++)
		printf("*");
	
	return 0;
}