#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char **argv) {
int n,m,i,l,h;
if (argv[3] == NULL) {
        printf("Usage: frame <height> <width> <text>");
	return 0;
}
if ((((atoi(argv[2]) - strlen(argv[3]))/2) <= 0) || (atoi(argv[1])<=2) || (atoi(argv[2])<=2)) {
	printf("Error");
	return 0;
}
	h=(atoi(argv[2])-strlen(argv[3]))/2;
	for (n=0; n < atoi(argv[1]); n++) {
		if (n == 0 || n == atoi(argv[1])-1) {
			for(m=0; m< atoi(argv[2]); m++)
				printf("*");
		}
		else {
			if (n!=(atoi(argv[1])-1)/2) {
				for(i=0; i<atoi(argv[2]);i++)
					if(i==0 || i==atoi(argv[2])-1)
						printf("*");
					else
						printf(" ");
			}
			else {
				printf("*");
				for(l=1;l<h; l++)
					printf(" ");
				printf("%s", argv[3]);
				for(l=h+strlen(argv[3]); l< atoi(argv[2])-1; l++)
					printf(" ");
				printf("*");
			}
		}	
		printf("\n");
	}	
	return 0;
}