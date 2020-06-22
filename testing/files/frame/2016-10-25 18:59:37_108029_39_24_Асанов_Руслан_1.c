#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char **argv){
    if(argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int x = atoi(argv[1]), y = atoi(argv[2]);
    char arr[1000];
    strcpy(arr, argv[3]);
    int len = strlen(arr);
    int i = 0, k = 0, j = 0, s = 0, c = 0;
    if(len > y - 2 || x == 2){
        printf("Error");
        return 0;
    }
    for(i = 0; i < y; i++){
        printf("*");
    }
    printf("\n");
    int save1 = 0, save2 = 0;
    save1 = (x - 1) / 2;
    save2 = (y - 2 - len) / 2;
    int check1 = 0, check2 = 0;
            for(j = 1; j < x - 1; j++){
    		if(j == save1){
    			printf("*");
    			for(i = 0; i <= save2; i++){
    				if(check1 == save2){
    					for(s = 0; s < len; s++){
    						printf("%c", arr[s]);
						}
						while(check2 != check1){
							printf(" ");
							check2++;
						}
						if((y - 2 - len) % 2 != 0){
							printf(" ");
						} 
						break;
					}
					printf(" ");
					check1++;
				}
				printf("*");
				printf("\n");
			}
			else{
				printf("*");
				for(k = 1; k < y - 1; k++){
					printf(" ");
				}
				printf("*");
				printf("\n");
			}
	}
    for(i = 0; i < y; i++){
        printf("*");
    }
    return 0;
}