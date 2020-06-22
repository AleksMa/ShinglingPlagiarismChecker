#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc!=4)
  {  
    printf("usage: frame <height> <width> <text> \n");
    goto end;
  }
  
  char *s;
  int i,j,x,y,n,t,k;
  y=atoi(argv[1]);
  x=atoi(argv[2]);
  s=argv[3];
  n=strlen(s);
  if (x<n+2)
  {printf("Error\n"); goto end;}
  if (y<3)
  {printf("Error\n"); goto end;}    

  for (i=0; i<x; i++)
    printf("*");
  printf("\n");
  if (y%2==0)
    k=y/2-1;
  else
    k=y/2;
  for (j=1; j<y-1; j++)
  {
    if (j==k)
    {
      printf("*");
      for (i=1; i<(x-n)/2; i++)
        printf(" ");
      printf("%s",s);
      if ((x-n)%2==0) 
	t=(x-n)/2;
      else
	t=(x-n)/2+1;
      for (i=1; i<t; i++)
	printf(" ");     
      printf("*\n");
    }
    else
    {
      printf("*"); 
      for (i=1; i<x-1; i++)
	printf(" ");
      printf("*\n");
    }
  }
  for (i=0; i<x; i++)
    printf("*");  
  printf("\n");
  
  end: 
  return 0;
}