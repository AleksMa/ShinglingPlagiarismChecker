
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
        int height = 0, width = 0, i = 0, j = 0;
	int startPosition = 0, finishPosition = 0;	

	if(argc != 4) {
		printf("usage: frame <height> <width> <text>");
		return 1;
	}
    height = atoi(argv[1]);
	width = atoi(argv[2]);
	if((strlen(argv[3]) > width - 2) || (height < 3)) {
		printf("Error");
		return 2;
	}	

	startPosition = (width - strlen(argv[3])) / 2; 
	finishPosition = startPosition + strlen(argv[3]);
	for(i = 0; i < height; i++) {
		if(i == 0 || i == height - 1) {
			for(j = 0; j < width; j++)
				printf("*");
		}
		else if(i == height / 2 - !(height % 2)) {
			for(j = 0; j < width; j++) {
				if(j == 0 || j == width - 1) 
					printf("*");
				else if(j >= startPosition && j < finishPosition)
					printf("%c", *(argv[3] + j - startPosition));
				else
					printf(" ");
			}
		}
		else {
			for(j = 0; j < width; j++) {
				if(j == 0 || j == width - 1)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");

	}
	return 0;
} 
