#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
        int h;
	int w;
	int ls;
	int h1;
	int w1;
	int i;
	int j;
	char *s;
	char *e;
	
	if (argc!=4)
	{
		printf("usage: frame <height> <width> <text>\n");
		return 0;
	}
	
	
	
	h = strtol (argv[1], &e, 10);
	w = strtol (argv[2], &e, 10);;
	s = argv[3];
	ls = strlen(s);
	h1 = (h-3)/2;
	w1 = (w-ls-2)/2;
	i=0;
	
	if (h1<0)
	{
		printf("error\n");
		return 0;
	}
	
	if (w1<0)
	{
		printf("error\n");
		return 0;
	}
	
	while(i++<w)
	{
		printf("*");	
	}
	printf("\n");
	i=0;
	
	while(i++<h1)
	{
		printf("*");
		
		j=0;
		
		while(j++<w-2)
		{
			printf(" ");
		}
		
		printf("*\n");
	}
	
	printf("*");
	
	i=0;
	
	while(i++<w1)
	{
		printf(" ");
	}
	
	printf("%s", s);
	
	i=0;
	
	while(i++<(w-ls-w1-2))
	{
		printf(" ");
	}
	
	printf("*");
	printf("\n");
	
	i=0;
	
	while(i++<(h-h1-3))
	{
		printf("*");
		
		j=0;
		
		while(j++<w-2)
		{
			printf(" ");
		}
		
		printf("*\n");
	}
	
	i=0;
	
	while(i++<w)
	{
		printf("*");	
	}
	
	printf("\n");
	return 0;
}