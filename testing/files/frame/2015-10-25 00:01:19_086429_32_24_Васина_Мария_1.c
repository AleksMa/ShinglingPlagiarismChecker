
#include <stdio.h>
#include <string.h>
int main (int argc, char **argv)
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 1;
	}
	int h, w, l, ots, mid, i, j;	

	h=atoi(argv[1]);
	w=atoi(argv[2]);	
	l=strlen(argv[3]);
	char *text;
         text=argv[3]; 

	if (l>(w-2) || h<3){
	printf("Error");
	return 1;
	}

	for (i=0; i<w-1; i++) printf("%c",'*');
	printf("%c\n",'*');

	if (h%2!=0) mid=(h-2)/2;
		else mid=h/2-2;
	ots=(w-l-2)/2;

	for (i=0; i<h-2; i++){
		printf("%c",'*');
		if (i!=mid)
			for(j=0; j<w-1; j++)
				if (j!=w-2) printf("%c",' ');
					else printf("%c\n",'*');
			else 
				for (j=0; j<w-1; j++){
					if (j<ots) printf("%c",' ');
					if (j==ots) printf("%s",text);
					if (j>=ots+l && j!=w-2) printf("%c",' ');
					if (j==w-2) printf("%c\n",'*');
				}
	}
	for (i=0; i<w-1; i++) printf("%c",'*');
	printf("%c\n",'*');				
}