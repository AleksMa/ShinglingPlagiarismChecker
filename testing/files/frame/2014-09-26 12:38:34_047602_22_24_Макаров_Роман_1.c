#include <stdio.h>
#include <string.h>
int main (int argc, char const *argv[])
{
        int h, w, i, j, l, h1, w1;
	if ((argc > 4)||(argc < 4)){
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	h = atoi(argv[1]);
	w = atoi(argv[2]);
	l = strlen(argv[3]);
	h1 = h;
	if ((strlen(argv[3]) > w-2) || (h < 3)){
		printf("Error\n");
		return 0;
	}
	for(i = 0; i < w; i++)
		printf("*");
	//printf("\n");
	h = (h-2)/2-1+(h%2);
	for(i = 0; i < h; i++){
		printf("\n");
		printf("*");
		for(j = 0; j < w-2; j++)
			printf(" ");
		printf("*");	
	}
	printf("\n");
	printf("*");
	w1 = (w-2-l)/2;
	for(i = 0; i < (w-2-l)/2; i++)
		printf(" ");
	printf("%s", argv[3]);
	for(i = 0; i < w-2-l-w1; i++)
		printf(" ");
	printf("*");
	for(i = 0; i <= h-(h1%2); i++){
		printf("\n");
		printf("*");
		for(j = 0; j < w-2; j++)
			printf(" ");
		printf("*");	
	}
	printf("\n");
	for(i = 0; i < w; i++)
		printf("*");
	return 0;
}