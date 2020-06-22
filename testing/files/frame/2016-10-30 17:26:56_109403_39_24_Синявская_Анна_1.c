
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int i, j, emp, emp1, sp, sp1;
	char l,h;
	char *s;
	if (argc!=4)
	{
	printf("Usage: frame <height> <width> <text>\n");
	return 1;
	} 
	else 
	{
		h = atoi(argv[1]);
		l = atoi(argv[2]);
		s = argv[3];
	}
	if ((h<=2) || (strlen(s)>(l-2)))
	{
                printf("Error");
                return 0;
	}
	else 
	{
		for (i=1; i<=l; i++) 
                        printf("*");
		printf("\n");
		emp = h - 3; 
		emp1 = emp/2;
		emp = emp - emp1;
		for (j=1; j<=emp1; j++)
		{
			printf("*");
			for (i=1;i<(l-1);i++)
                                printf(" ");
			printf("*");
			printf("\n");
		}
		sp = l - 2 - strlen(s);
		sp1 = sp/2;
		sp = sp - sp1;
		printf("*");
		for (i=1; i<=sp1;i++) 
                        printf(" ");
		printf("%s", s);
		for (i=1; i<=sp;i++)
		        printf(" "); 
		printf("*\n");
		for (j=1; j<=emp; j++)
		{
			printf("*");
			for (i=1;i<(l-1);i++)
                                printf(" ");
			printf("*");
			printf("\n");
		}
		for (i=1; i<=l; i++)
		        printf("*");
		printf("\n");
	}
        return 0;
}