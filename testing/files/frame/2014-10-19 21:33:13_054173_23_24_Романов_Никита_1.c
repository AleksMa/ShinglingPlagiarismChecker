#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) 
{ 
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int h,w;
	h=atoi(argv[1]);
	w=atoi(argv[2]);
	char *text=argv[3];
	if ((h<=2) || (w<(strlen(text)+2))) {
		printf("Error\n");
		return 0;
	}
	int i,k,m,sh,sw;
	m=-1;
	sh=(h-1)/2;
	sw=(w-strlen(text))/2;	
	for (i=0;i<h;++i) {
		if ((i==0) || (i==(h-1)))
			for (k=0;k<w;k++) 
				printf("*");
		else if (i != sh)
				for (k=0;k<w;k++)
					if ((k==0) || (k==(w-1)))
						printf("*");
					else 
						printf(" ");
		else
			for (k=0;k<w;k++)
				if ((k==0) || (k==(w-1)))	 
					printf("*");
				else if ((k<sw) || (k>=(sw+strlen(text))))
					printf(" ");
				else {
					++m;
					printf("%c", text[m]);
				}
		printf("\n");
	}
	return 0;   
}