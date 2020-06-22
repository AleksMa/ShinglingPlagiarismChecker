#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int s_length(char* s) {
        //unsigned int i = 0;
	//while (s[i] != '\n')
	//	i++;
	//
	//return i;
	return strlen(s);
}

void print_string(char* s) {
	unsigned int i = 0, len = s_length(s);
	while (i < len) {
		printf("%c", s[i]);
		i++;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	
	unsigned int h = atoi(argv[1]), w = atoi(argv[2]);
	char* s = argv[3];
	
	if (((int)(w - s_length(s)) < 2) || (h <= 2)) {
		printf("Error\n");
		return 0;
	}
	
	unsigned int str_num = h / 2, free_w = w - s_length(s) - 2, i = 0;
	if (h % 2 == 0) str_num--;
	
	while (i < w) {
		printf("%c", '*');
		i++;
	}
	printf("\n");
	
	i = 1;
	unsigned int j;
	while (i < h - 1) {
		j = 0;
		printf("%c", '*');
		
		if (i == str_num) {
		    while (j < free_w / 2) {
		  	    printf("%c", ' ');
		  	    j++;
		    }
		
		    print_string(s);
		    
		    j = 0;
		    while (j < free_w - free_w / 2) {
		    	printf("%c", ' ');
		    	j++;
			}
	    }
	    else
	    	while (j < w - 2) {
	    		printf("%c", ' ');
	    		j++;
			}
		
		printf("%c\n", '*');
		i++;
	}
	
	i = 0;
	while (i < w) {
		printf("%c", '*');
		i++;
	}
	
	return 0;
}