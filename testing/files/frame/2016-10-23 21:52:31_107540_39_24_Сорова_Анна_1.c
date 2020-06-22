#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv) {
        int a ,b ,len, i=0, n=0, k=0, x = 0, y = 1,z=0;
        if (argc != 4) {
                printf("Usage: frame <height> <width> <text>\n");
                return 0;
        }
        a = atoi(argv[1]); 
        b = atoi(argv[2]); 
        len = strlen(argv[3]);
	if ((a<3) && ((b<3) || (a<len+2))) {
                printf("Error"); 
                return 0; 
        }
	if ((b<len+2) && ((a<len+2) || (b<3))) {
                printf("Error"); 
                return 0;
        }
	if (b>=len+2) {
		if (b == len+2) 
			z = 1;
		if (a%2 == 0) 
                        x =-1;
		if (((b%2 == 1) && (len%2==1)) || ((b%2 == 0) && (len%2 == 0)))           //a%2 == 1 (так было)
			y = 0;
		for (i=0; i<b-1; i++)
			printf("*");
		printf("*\n");
		for (k=0; k<(a-2)/2+x; k++) {                       
			printf("*");
		        for (n = 0; n<(b-2); n++)
			        printf(" ");
		        printf("*\n");
	        }
        	printf("*");
	        for (n = 0; n<(b-2-len)/2; n++)                      
		        printf(" ");
	        printf("%s", argv[3]);
	        for (n = 0; n<(b-2-len)/2+y-z; n++)                 
		        printf(" ");
	        printf("*\n");
	        for (k=0;k<(a-2)/2;k++) {			
		        printf("*");
		        for (n = 0; n<(b-2) ; n++)
			        printf(" ");
		        printf("*\n");
	        }
	        for (i=0; i<b; i++)
		        printf("*");
	} 
        else {
		if (a == len+2) 
			z = 1;
		if (b%2 == 0) 
                        x =-1;
		if (((a%2 == 1) && (len%2==1) && (a!=len+2)) || ((a%2 == 0) && (len%2 == 0) && (a != len+2)))   //b%2 == 1 (так было)
			y = 0;
		for (i=0; i<a-1; i++)
			printf("*");
		printf("*\n");
		for (k=0; k<(b-2)/2+x; k++) {                       
			printf("*");
			for (n = 0; n<(a-2) ; n++)
				printf(" ");
			printf("*\n");
		}
		printf("*");
		for (n = 0; n<(a-2-len)/2; n++)                      
			printf(" ");
		printf("%s", argv[3]);
		for (n = 0; n<(a-2-len)/2+y-z; n++)                 
			printf(" ");
		printf("*\n");
		for (k=0;k<(b-2)/2;k++) {			
			printf("*");
			for (n = 0; n<(a-2) ; n++)
				printf(" ");
			printf("*\n");
		}
		for (i=0; i<a; i++)
			printf("*");
        }
	return 0;
 }