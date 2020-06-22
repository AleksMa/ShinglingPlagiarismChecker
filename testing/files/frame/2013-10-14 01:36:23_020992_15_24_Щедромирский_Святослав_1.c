#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
        int i, j;
	char h = atoi(argv[1])-2;
	char l = atoi(argv[2]);
	char *s = argv[3];
	if(argc!=4) {
    		printf("Usage: frame <height> <width> <text>\n");
    		exit(1);
  	}
	if ((strlen(s)>l-2) || (h<1)) printf("Error\n");
	else {
		int mainstars() {
			int k;
			if (h%2!=0) k=h/2;
			else k=h/2-1;
			for (j=0;j<k;j++) {		
				printf("*");
				for(i=2;i<l;i++) printf(" ");
				printf("*\n");
			}
		}
		for(i=1;i<l;i++) printf("*");
		printf("*\n");
		mainstars();
		printf("*");
		if ((strlen(s)%2!=0)&&(l%2==0)) {
			for(i=0;i<((l+2-strlen(s)-2)/2)-1;i++) printf(" ");
			printf("%s", s);
			for(i=0;i<((l+2-strlen(s)-2)/2);i++) printf(" ");
		}else{
			if ((strlen(s)+2)!=l) {
				if ( ((strlen(s)%2==0)&&(l%2==0)) || ((strlen(s)%2!=0)&&(l%2!=0)) ) for(i=0;i<((l-strlen(s)-2)/2);i++) printf(" ");
				else for(i=0;i<((l-strlen(s)-2)/2);i++);
			}
			printf("%s", s);
			if ((strlen(s)+2)!=l) {
				if ( ((strlen(s)%2==0)&&(l%2==0)) || ((strlen(s)%2!=0)&&(l%2!=0)) ) for(i=0;i<((l-strlen(s)-2)/2);i++) printf(" ");
				else for(i=0;i<=((l-strlen(s)-2)/2);i++) printf(" ");
			}
		}
		printf("*\n");
		if ((h%2)==0) h+=2;
		mainstars();
		for(i=1;i<l;i++) printf("*");
		printf("*\n");
	}
	return 0;
}