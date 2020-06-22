#include<stdio.h>
#include<string.h>
    
int main(int argc,char** argv)
{
  int x,y,i,j,h=0;
  char *s;
  char *m;
  if (argc!=4) {
          printf("Usage: frame <height> <width> <text>");
    return 0;
  }
  y=strtol(argv[1],&s,10);
  x=strtol(argv[2],&s,10);
  m=argv[3];
  if (strnlen(m,20)>x-2 || y<3 || x<2) {
    printf("Error\n");
    return 0;
  }
  for(i=0;i<x;i++)
    printf("*");
  printf("\n");
  for(i=0;i<(y-3)/2;i++) {
    printf("*");
    for(j=0;j<x-2;j++)
      printf(" ");
    printf("*");
    printf("\n");
  }
  
  h=(x-2-strnlen(m,20))/2;
  printf("*");
  for(i=0;i<h;i++)
    printf(" ");
  for(i=0;i<strnlen(m,20);i++)
    printf("%c",m[i]);
  for(i=0;i<x-2-h-strnlen(m,20);i++)
    printf(" ");
  printf("*");
  printf("\n");
  
  for(i=0;i<((y-3)-(y-3)/2);i++) {
    printf("*");
    for(j=0;j<x-2;j++)
      printf(" ");
    printf("*");
    printf("\n");
  }
  for(i=0;i<x;i++)
    printf("*");
  printf("\n");
  
  return 0;
}