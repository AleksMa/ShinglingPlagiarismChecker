#include <stdio.h>
#include <stdlib.h> 

void strh(int a)
{
        int i;
	for(i=0; i<a; i++)
	{
		printf("*");
	}
	printf("\n");
}

void strv(int h2, int a)
{
	int i, j;
	for(j=0; j<h2; j++)
	{
		printf("*");
		for(i=2; i<a; i++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}

void strc(int a1, int a2, int len, char *p)
{
	int i;
	printf("*");
	for(i=1; i<a1; i++) printf(" ");
	printf("%s", p);
	for(i=1; i<a2; i++) printf(" ");
	printf("*\n");
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int h=0, a=0, len, h2=0, a2=0;
	h = atoi(argv[1]);
	a = atoi(argv[2]);
	for(len=0; argv[3][len] != '\0'; len++);
	if(h<3 || a<len+2)
	{
		printf("Error\n");
	}
	else
	{
		if(h != (h/2*2)) h2 = (h-3)/2;
		else h2 = (h-4)/2;
		if((a-len) == ((a-len)/2*2)) a2 = (a-len)/2;
		else a2 = (a-len-1)/2;
		strh(a);
		strv(h2, a);
		strc(a2, a-len-a2, 0, argv[3]);
		strv(h-3-h2, a);
		strh(a);
	}
	return 0;
}