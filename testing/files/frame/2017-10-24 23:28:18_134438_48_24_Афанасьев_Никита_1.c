#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
        int n_raw = 0;
	int n_column = 0;   
	int j = 0;
	int k = 0;
	int ls = 0;
	int i = 0;
	
	if(argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
	}
	else {
		sscanf(argv[1], "%d", &n_raw);
		if (n_raw %2 == 0) i = 1;
		sscanf (argv[2], "%d", &n_column);
		if (argc == 4)  ls = strlen(argv[3]);		
		if ((ls > (n_column - 2))|| (n_raw < 3)) {
			printf ("Error\n");
		}
		else {
			for (j = 0; j < n_raw; j++){
				if ((j == 0) ||(j == n_raw-1)) {
					for (k = 0; k < n_column; k++) printf("*");
						printf("\n");
				}
				else if (((j > 0) && (j < (n_raw/2)-i  )) || (j > (n_raw/2-i))) {
					printf("*");					
					for(k = 0; k < ((n_column - 2)); k++) printf(" ");
					printf("*\n");
				}
				else {
					printf("*");
					for(k = 0; k < ((n_column - ls - 2)/2); k++) printf(" ");
					if (ls > 0) printf("%s", argv[3]); 
					for (k = ((n_column + ls - 2)/2 ); k < (n_column - 2); k++) printf(" ");
					printf("*\n");
				}
			}	
		}
	}
	return 0;
}
