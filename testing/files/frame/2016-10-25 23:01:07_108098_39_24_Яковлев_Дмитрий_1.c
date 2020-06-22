#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc < 4) printf("Usage: frame <height> <width> <text>\n");
        else {
                int a,b,c,d,i,j,l;
                a = atoi(argv[1]);
                b = atoi(argv[2]);
                l = strnlen(argv[3], 100);
                if ((a<3) || (b<3)) printf("Error\n");
                else {
                if ((a-2)%2 == 0) c = (a-2) / 2;
                else c = (a-2) / 2 + 1;
        	if ((b - l)%2 == 0) d = ((b - l) / 2); 
        	else  d = ((b - l) / 2);
	        if (l > (b - 2)) printf("Error");
	        else {
		        for (i = 0; i < b; i++) printf("*");
		        printf("\n");
		        for (i = 1; i < a - 1; i++) {
			        if (i == c) {
				        printf("*");
				        j = 1; 
				        while (j != d) {
					        printf(" ");
					        j=j+1;
				        }
				        printf("%s", argv[3]);
				        j = j + l;
				        while (j != b - 1) {
					        printf(" ");
				        	j=j+1;
				        }
				        printf("*");
				        printf("\n");
			        } else {
				        printf("*");
				        for (j = 1; j != b-1; j++) printf(" ");
				        printf("*");
				        printf("\n");
			        }
		        }
		        for (i = 0; i < b; i++) printf("*");
                }
                }
        }
	return 0;
}