#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//created by Benji(2014)

void printStr(int width,int heigth,int length, char *a){

}
int main(int argc, char **argv) {
        int height, width, length, i = 0, j = 0, k = 0, h = 0;
        if (argc != 4){
        	printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
        
	height = atoi(argv[1]);
        width = atoi(argv[2]);
	length = strlen(argv[3]);
        
	if (height < 3 || width < (length + 2)){
		printf("Error\n");
		return 0;
	}
	for(i=1;i<=height;i++){
		if(i==1){
				for (j = 0; j < width; j++)printf("*");
				printf("\n");
		}
		else{
			printf("*");

			if(i==(height+1)/2){
				for(j=0;j<(width-(length+2))/2;j++)printf(" ");
				printf("%s",argv[3]);
				for(j+=length;j<width-2;j++)printf(" ");
				printf("*\n");
			}
			else{
				if(i==height)
					for (j = 0; j < width-1; j++)printf("*");
				else{
					for(j=0;j<(width-2);j++)printf(" ");
					printf("*\n");}
				}
				
		}
		
	}
	
	return 0;
}