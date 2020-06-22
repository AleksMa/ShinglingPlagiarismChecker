#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int h,w, i,x,j,n;
	char *e, *s;
	if ((argc < 4) || (argc > 4))
	{
		printf("usage: frame <height> <width> <text>\n");
		return 0;
	}
	h = strtol(argv[1], &e, 10);
	w = strtol(argv[2], &e, 10);
	x=strnlen(argv[3],100);
	if (x>(w-2))
	{
		printf("Error\n");
		return 0;
	}
        if (h<3)
        {
                printf("Error\n");
                return 0;
        }
	for (i=0; i<w; i++)
		printf("*");
	if ((h % 2) == 0)
		n =( h / 2) -1;
	else
		n = h/2;
	for (i=1; i < n; i++)
	{
		printf("\n*");
		for (j=1; j<w-1; j++)
			printf(" ");
		printf("*");
	}
	printf("\n*");
	for (i=1;i<(w/2)-(x/2); i++)
		printf(" ");
	printf("%s", argv[3]);
	for (i=(w/2)-(x/2)+x; i<w-1; i++)
		printf(" ");
	printf("*");
	for (i=n+1; i < h-1; i++)
	{
		printf("\n*");
		for (j=1; j<w-1; j++)
			printf(" ");
		printf("*");
	}
	printf("\n");
	for (i=0;i<w;i++)
		printf("*");

	return 0;
}	


