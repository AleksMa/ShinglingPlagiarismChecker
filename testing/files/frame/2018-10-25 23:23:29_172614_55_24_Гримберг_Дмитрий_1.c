#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void visota (int w)
{
    int i = 0;
    for (i = 0; i < w; i++)
        printf("*");
    printf("\n");
}
 
void shirina (int w, int h)
{
    int i = 0, j = 0, mid;
    mid = ((h-2)/2-1);
    for (i= 0; i <= mid; i++) {
        printf("*");
        for (j = 0; j < w-2; j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
}
 
void txt(int w, char *text)
{
    int i, mid1,mid2,s;
    s = strlen(text);
        printf("*");
    mid1=(((w-2) - s)/2);
	mid2=((w-2) - s)-mid1;
    for (i = 0; i <= mid1-1; i++) 
          printf(" ");
    printf("%s", text);
    for (i = 0; i <= mid2-1; i++) 
          printf(" ");
	printf("*");
    printf("\n"); 
}

int main(int argc, char *argv[])
{
	int h,w;
  if (argc!=4) { printf("Usage: frame <height> <width> <text>\n"); 
		return 1; }
  h = atoi(argv[1]);
  w = atoi(argv[2]);
  char *text = argv[3];
  if (strlen(text)>(w-2))
  {
	printf("Error");
	return 1;
  }
  if (h<=2)
  {	
	printf("Error");
	return 1;
  }
  visota(w);
  shirina(w,h-1);
  txt(w,text);
  shirina(w,h);
  visota(w);
}