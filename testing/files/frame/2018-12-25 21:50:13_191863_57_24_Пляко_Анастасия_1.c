#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Line(long h){
        for(unsigned long i=0; i<h; i++){
		printf("*");
	}
	printf("\n");
}

int Column(long h){
	printf("*");
	for(unsigned long i=0; i<h-2; i++){
		printf(" ");
	}
	printf("*\n");
}

int Text(long h, char* t){
	printf("*");
	if((strlen(t)+h)%2 == 0){
		for(unsigned long i=0; i<(h-2-(strlen(t)))/2; i++){
			printf(" ");
		}
		printf("%s", t);
		for(unsigned long i=0; i<(h-2-(strlen(t)))/2; i++){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	else{
		for(unsigned long i=0; i<(h-3-(strlen(t)))/2; i++){
			printf(" ");
		}
		printf("%s", t);
		for(unsigned long i=0; i<1+(h-3-(strlen(t)))/2; i++){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	long h, w;
	unsigned long i;
	char* t;
	if(argc != 4){
		printf("Usage: frame <height> <width> <text>");
	}
	else{
		w = atoi(argv[1]);
		h = atoi(argv[2]);
		t = argv[3];
		if ((strlen(t) > h-2) || (w<3)){
			printf("Error");
		}
		else{
			Line(h);
			if (w%2 == 0){
				for (i=0; i<((w/2)-2); i++){
					Column(h);
				}
				Text(h, t);
				for (i=0; i<((w/2)-1); i++){
					Column(h);
				}
			}
			else{
				for (i=0; i<((w-1)/2)-1; i++){
					Column(h);
				}
				Text(h, t);
				for (i=0; i<((w-1)/2)-1; i++){
					Column(h);
				}
			}
			Line(h);
		}
	}
	return 0;
} 