#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char** argv) 
{
        int width, height;
	int linefortext, numfortext, len;
	char* text;
	if(4 != argc){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	height=atoi(argv[1]);
	width=atoi(argv[2]);
	text=argv[3];
	len=strlen(text);
	if((height < 3)||(width < len+2)){
		printf("Error");
		return 0;
	}
	linefortext=(height-1)/2;
	numfortext=(width-len)/2;
	for(int i =0; i<height; ++i){
		if(i==0 || i==height-1){
			for(int j=0; j<width; ++j){
				printf("*");
			}
			printf("\n");
		}
		else if(i==linefortext){
			printf("*");
			for(int j=1; j<numfortext; ++j){
				printf(" ");
			}
			printf("%s", text);
			for(int j=numfortext+len; j<width-1; ++j){
				printf(" ");
			}
			printf("*\n");
		}
		else{
			printf("*");
			for(int j=1; j<width-1; ++j){
				printf(" ");
			}
			printf("*\n");
		}
	}
	return 0;
}