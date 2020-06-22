
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char ** argv)
{
        int i, j, n, h, w;
	if (argc==4) {
		h=atoi(argv[1]);
		w=atoi(argv[2]);
		n=strlen(argv[3]);
		if (((w-1)>n)&&(h>2)) {
			for(i=0; i<h; i++) {
				for(j=0; j<w; j++) {
					if ((i==0)||(i==h-1)) printf("*");
					else if (i==(h-1)/2) {
						if ((j==0)||(j==w-1)) printf("*");
						else {
							if ((w%2==1)||(n%2==0)) {
								if (j==(w/2-n/2)) {
									printf("%s", argv[3]);
									j=j-1+n;
								}
								else printf(" ");
							}
							else {
								if (j==(w/2-n/2-1)) {
									printf("%s", argv[3]);
									j=j-1+n;
								}
								else printf(" ");
							}
						}
					}
					else {
						if ((j==0)||(j==w-1)) printf("*");
						else printf(" ");
					}
				}
				printf("\n");
			}
		}
		else printf("Error");
	}
	else printf("Usage: frame <height> <width> <text>");
}