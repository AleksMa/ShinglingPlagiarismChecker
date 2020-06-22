#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        char *word = argv[3];
    int a, b,i;
    if (argc != 4)
        printf("Usage: frame <height> <width> <text>\n");
       else {
       i = strlen(word), a = atoi(argv[1]), b = atoi(argv[2]);
	if (i>b-2 || a<=2){ printf ("Error\n"); return 0;};
	int k=1;
	int j,s,n;
	s=0;n=(b-i-2)/2;
	if (a%2==0) j=a/2;
	else j=a/2+1;
	while (k<=a){
		s=0;
		if (k==a || k==1) while (s<b) {
							if (s== b-1) printf ("*\n");
							else printf ("*");
							s++;
							}
		else while (s<b){
				if (s==0) printf ("*");
				if (k != j) while (s<b-2) { printf(" "); s++;}
				else {
					while (s <n) {printf(" "); s++;};
					printf("%s", word) ; s=s+i+1;
					while (s<=b-2) {printf(" "); s++;};
					};
				if (s==b-1) printf("*\n");
				s++;
				};
		k++;
	};
	};
	return 0;
}