 
#include <stdio.h>
#include <string.h>


int wlength (char *s)
{
    int temp = 0;
    while (*s++)
        temp++;
    return temp;
}

void fill (int a)
{
    int i;
    for (i = 0; i < a; i++)
        printf("*");
    printf("\n");
}

void space (int a, int b)
{
    int i, j;
    a = a - 2;
    for (i = 0; i < a/2; i++)
    {
        printf("*");
	for ( j = 0; j < b-2; j++)
	    printf(" ");
	printf("*\n");
    }      
}

void cout(int a, int b, char *s)
{
    int length = wlength(s);
    b = b - 2;
    printf("*");
    int i, count = 0;
    for (i = 0; i < (b - length)/2; i++)
    {
      printf(" ");
      count++;
    }
    printf("%s",s);
    for (i = 0; i < (b - count - length); i++)
        printf(" ");
    printf("*\n");
}
int main(int argc, char *argv[])
{
    int a = atoi(argv[1]); char b = atoi(argv[2]); char *s = argv[3];
    int j = 0,i = 0, temp = 0;
    if (argc < 4)
	printf("Usage: frame <height> <width> <text>\n");
    else
    {
        int length = wlength(s);
        if( ((b-2)-length < 0) || ( a <= 2) ) 
	    printf("Error");
        else
        {
            fill(b);
            space(a-1,b);
            cout(a,b,s);
            space(a,b);
            fill(b);
        }
    }
    return 0;
}

