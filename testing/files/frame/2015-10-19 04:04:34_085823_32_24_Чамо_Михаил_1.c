#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int s, i, q, j, n = 0;
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;}
	q = atoi(argv[1]);
	j = atoi(argv[2]);
	s = strlen(argv[3]);
	if ((s > j - 2) || (q < 3)) {
		printf("Error");
		return 0;}
	for (n = 0; n < j; n++)
		printf("*");
	printf("\n"); 
	for (n = 0; n < (q - 1) / 2 - 1; n++) {
		printf("*");
		for (i = 0; i < j - 2; i++)
			printf(" ");
		printf("*\n");
		}
	printf("*");
	for (i = 0; i < (j - 2 - s) / 2; i++)
		printf(" ");
	printf("%s", argv[3]);
	for (i = 0; i < j - 2 - s - (j - 2 - s) / 2; i++)
		printf(" ");
	printf("*\n");
	for (n = 0; n < q - 2 - (q - 1) / 2; n++) {
		printf("*");
		for (i = 0; i < j - 2; i++)
			printf(" ");
		printf("*\n");
		}
	for (n = 0; n < j; n++)
		printf("*");
	return 0;
}