#include <stdio.h>

int main(int argc, char *argv[]) {
        if (argc!=4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int i, i2, strl;
	int wdt = atoi(argv[1]);
	int len = atoi(argv[2]);
	int slen = strlen(argv[3]);
	if((len-1<=slen) || (len<=0) || (wdt<3)) {
		printf("Error\n");
		return 0;
	}
	for (i=0;i<len;i++)
		printf("*");
	for(i2=1;i2<(wdt-1)/2;i2++) {
		printf("\n*");
		for(i=2;i<len;i++)
			printf(" ");
		printf("*");
	}
	printf("\n*");
	for(i=1;i<=(len-slen-2)/2;i++)
		printf(" ");
	printf("%s", argv[3]);
	for(i=1;i<=(len-slen-1)/2;i++)
		printf(" ");
	printf("*\n");
	for(i2+=2;i2<wdt;i2++)
	{
		printf("*");
		for(i=2;i<len;i++)
			printf(" ");
		printf("*\n");
	}
	for (i=0;i<len;i++)
		printf("*");
	printf("\n");
	return 0;
}