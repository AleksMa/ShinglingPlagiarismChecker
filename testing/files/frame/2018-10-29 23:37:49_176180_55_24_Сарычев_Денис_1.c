#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void aline (int w)

{
        for (int i=0; i<w; i++)
		printf("*");
		printf("\n");
}

void bline (int h, int w)

{
	for (int i=0; i<((h-2)/2); i++)

		{
			printf("*");

			for (int i=0; i<(w-2); i++)
				printf(" ");

			printf("*");
			printf("\n");
		}

}

void text (int w, char *t)

{
	int s=strlen(t), wa=((w-2)-s)/2, wb=((w-2)-s)-wa;

	printf("*");

	for (int i=0; i<wa; i++)
		printf(" ");

	printf("%s", t);

	for (int i=0; i<wb; i++)
		printf(" ");

	printf("*");
	printf("\n");    
}


int main (int f, char *frame[])

{

	int h=atoi(frame[1]);
	int w=atoi(frame[2]);
	char *t=frame[3];
	
	if (f!=4)
		{
			printf("Usage: frame <height> <width> <text>");
			printf("\n");
			return 0;
		}

	if (h<=2)
		{
			printf("Error");
			printf("\n");
			return 0;
		}

	if ((w-2)<strlen(t))
		{
			printf("Error");
			printf("\n");
			return 0;
		}

	aline(w);

	if ((h% 2)==1)
		bline(h, w);
    		else bline((h-1), w);

	text(w, t);
	bline(h, w);
	aline(w);
	return 0;
}