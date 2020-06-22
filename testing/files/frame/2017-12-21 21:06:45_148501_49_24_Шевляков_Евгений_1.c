#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
        int i, j;
	printf("\n");
	if(argc < 4){
		printf("Usage: frame <height> <width> <text>");
		return 0 ;
	}
	int str_len = strlen(argv[3]);
	int height_len = strlen(argv[1]);
	int width_len = strlen(argv[2]);
	int height = 0;
	int width = 0;
	for(i = 0; i < height_len;i++)
		height = height * 10 + (argv[1][i] - 48);
	for(i = 0; i < width_len; i++)
		width = width * 10 + (argv[2][i]-48);
	if((str_len > width - 2)||(height < 3)){
		printf("Error");
                return 0;
	}
	int width_half = width / 2;
	int height_half = height / 2;

	printf("\n");
	for(i = 0; i < width; i++)
		printf("*");
	printf("\n");
	for(i = 0; i < (height-2) / 2 - ((height+1) % 2); i++){
		printf("*");
		for(j = 0; j < (width - 2); j++)
			printf(" ");
		printf("*\n");
	}
	printf("*");
	for(i = 0;i < (width - str_len - 2)/2;i++)
		printf(" ");
	printf("%s",argv[3]);
	for(i = 0;i < (width - str_len - 2)/2 + ((width - 2 - str_len) % 2);i++)
		printf(" ");
	printf("*\n");
	for(i = 0; i < (height - 2) / 2 ;i++){
		printf("*");
		for(j = 0; j < (width  -2); j++)
			printf(" ");
		printf("*\n");
	}
	for(i = 0; i < width; i++)
		printf("*");


	printf("\n");
	return 0;
}
