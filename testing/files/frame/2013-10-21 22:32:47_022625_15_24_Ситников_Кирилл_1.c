#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv) {
        char h=atoi(argv[1]);
        char w=atoi(argv[2]);
	char *s=argv[3];
	int i,k,j;
	if (h%2==0) k=h/2-1;
	else k=h/2;
	if (argc!=4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	if ((h<3)||(w-2<strlen(s))) printf("Error");
		else {
			for (j=0;j<w;j++) printf ("*");
			printf("\n");
			for (i=1;i<h-1;i++) {
				if (i==k) {
					printf("*");
					for(j=1;j<(w-strlen(s))/2;j++) printf(" ");
					printf ("%s",s);
					for(j=1;j<w-strlen(s)-((w-strlen(s))/2);j++) printf(" ");
					printf("*\n");
				}
				else {
					printf("*");
					for(j=0;j<w-2;j++) printf(" ");
					printf("*\n");
				}
			}
			for (j=0;j<w;j++) printf ("*");
		}
	return 0;
}	