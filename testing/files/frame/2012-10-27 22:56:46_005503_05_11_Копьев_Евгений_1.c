
#include <stdio.h>
#include <string.h>

int main(int argc,char** argv)
{
  int x,y,i=0,j=0,h=0;
  char *s;
  char *k;
  if (argc!=4)  {
      printf("Введите высоту рамки. ширину рамки и само слово\n");
      return 0;
  }
  y=strtol(argv[1],&s,10);
  x=strtol(argv[2],&s,10);
  k=argv[3];
  if (strnlen(k,20)>x-2 || y<3) {
     printf ("ERROR\n");
     return 0;
  }
  for (i=0;i<x;i++)
    printf("*");
  printf("\n");
  for (i=0;i<(y-3)/2;i++)  {
    printf("*");
    for (j=0;j<x-2;j++)
      printf(" ");
    printf("*");
    printf("\n");
  }
  
  h=(x-2-strnlen(k,20))/2;
  printf("*");
  for(i=0;i<h;i++)
    printf(" ");
  for(i=0;i<strnlen(k,20);i++)
    printf("%c",k[i]);
  for(i=0;i<x-2-h-strnlen(k,20);i++)
    printf(" ");
  printf("*");
  printf("\n");
  
  for (i=0;i<((y-3)-(y-3)/2);i++)  {
    printf("*");
    for (j=0;j<x-2;j++)
      printf(" ");
    printf("*");
    printf("\n");
  }
  for (i=0;i<x;i++)
    printf("*");
  printf("\n");
  
  return 0;
}
