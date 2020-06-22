#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char* argv[]){

        if(argc != 4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int sh, hi, len_str;
	char* str;
	hi = atoi(argv[1]);
	sh = atoi(argv[2]);
	str = argv[3];
    len_str = strlen(str);
	if((hi < 3) || (sh < len_str + 2)){
		printf("Error");
		return 0;
	}


	for(int i = 0; i < hi; i++){
		for(int j = 0; j < sh; j++){
			if((i == 0) || (i == hi-1) || (j == 0) || (j == sh-1)){
				printf("*");
			}
			else if((i == ceil(hi/2.0-1)) && (j == (sh-len_str)/2)){
				printf("%s", str);
				j += len_str-1;
			}
			else 
				printf(" ");

		}
		printf("\n");
	}

	return 0;
}