#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Log(a) printf("%s\n",a)
#define LogN(a) printf("%ld\n",a)
#define MaxSize 256

int main(int argc, char **argv){
    if (argc != 4){
        	printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}	
	
	long high = atoi(argv[1]);
	long wight = atoi(argv[2]);
	long length = strnlen(argv[3],MaxSize);

	if ( high < 3 || length > (wight-2) ){
		printf("Error\n");
		return 0;
	}

	long place_str_high = (high + 1) / 2;
	long place_str_wight = (wight - length) / 2 + 1;
	//LogN(place_str_high);
	//LogN(place_str_wight);
	long i,k;

	//Верх
	for (i = 0; i < wight; i++) printf("*");
	printf("\n");
	for (k = 2; k < place_str_high; k++){
		printf("*");
		for (i = 1; i < wight-1; i++) printf(" ");
		printf("*\n");
	}
	
	//Строка
	printf("*");
	for (i = 2; i < place_str_wight; i++) printf(" ");
	printf("%s",argv[3]);
	for (i = place_str_wight + length; i < wight; i++) printf(" ");
	printf("*\n");

	//Низ
	for (k = place_str_high + 1; k < high; k++){
		printf("*");
		for (i = 1; i < wight-1; i++) printf(" ");
		printf("*\n");
	}
	for (i = 0; i < wight; i++) printf("*");
	printf("\n");

	return 0;
}