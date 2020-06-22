#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                                          
void print_line(int width){               
    for(int i = 0 ; i < width ; i++)      
	printf("*");                      
    printf("\n");                        
}

void print_row(int height , int width){
    for(int i = 0 ; i < height ; i++){
	int j = 0;
	printf("*");
	while(j < width - 2){
	    printf(" ");
	    j++;
	}
	printf("*\n");
    }
}

int main(int argc , char **argv){
    int i = 0 , j = 0;
    if(argc < 4){
	printf("Usage: frame <height> <width> <text>");
	return 0;
    }
    int height = atoi(argv[1]);               
    int width = atoi(argv[2]);
    char text[100];
    strcpy(text , argv[3]);
    int len = strlen(text);
    if(len > width - 2 || height < 3){
	printf("Error");
        return 0;
    }
    print_line(width);
    print_row((int)((height + 1)/2) - 2 , width);
    printf("*");
    while(i < (width - len)/2 - 1){
	printf(" ");
	i++;
    }
    printf("%s" , text);
    while(j < width - i - len - 2){
	printf(" ");
	j++;
    }
    printf("*\n");
    if(height % 2 != 0)        
        print_row((int)((height + 1)/2) - 2 , width);
    else
        print_row((int)((height + 1)/2) - 1 , width);
    print_line(width);
    return 0;
}