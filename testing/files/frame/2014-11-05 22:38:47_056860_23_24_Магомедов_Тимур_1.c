#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int height, width, length = 0, i, j, del, d;
  char *str;

  if ( argc != 4 )
    printf("Usage: frame <height> <width> <text>\n");
  else
  {
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    str = argv[3];
    if (strlen(str) > width - 2 || height == 2)
      printf("Error\n");
    else
    {
      for (i = 0; str[i] != '\0'; i++) length++;
      {
        for(i = 0; i < width; i++)
          printf("*");
	printf("\n");
	for(i = 2; i < height; i++)
	{
	  if(height%2==0)
	    del = 0;
	  else del = 1;
	  if(i == height/2 + del)
	  {
	    printf("*");
	    for(j = 0; j < ((width-2) - length)/2; j++)
	      printf(" ");
	    printf("%s", str);
	    for(j = 0; j < ((width - 2) - length) - ((width - 2) - length)/2; j++)
	      printf(" ");
	    printf("*\n");
	  }
	  else
	  {
	    printf("*");
	    for(j = 0; j < width - 2; j++)
	      printf(" ");
	    printf("*\n");
	  }
	}
      }
      for(i = 0; i < width; i++)
	printf("*");
      printf("\n");
    }
  }

  return 0;
}