
#include <stdio.h>
#include <stdlib.h>
 
#include <string.h>
int main(int argc, char** argv) {
  if (argc<4 || argc>4)
  {
    printf("%s", "Usage: frame <height> <width> <text>");
    return 0;
  }
  int w, h, l;
  h = atoi(argv[1]);
  w = atoi(argv[2]);
  l = strlen(argv[3]);
  if (w<l+2 || h-2<=0)
  {
    printf("%s", "Error");
  }
  else {
    int i, j;
    i=j=1;
    for (; i<=h; i++)
    {
      if (i==h || i==1)
      {
        for (j=0; j<w ; j++)
        {
          putchar('*');
        }
      }
      else if (i-(h+1)/2 == 0)
      {
        putchar('*');
        for (j=1; j<(w-l)/2; j++)
          putchar(' ');
        printf("%s", argv[3]);
        for (j=((w+l+2)/2); j<=w; j++)
        {
          if (w==j)
            putchar('*');
          else
            putchar(' ');
        }
      }
      else
      {
        for (j=1;j<=w;j++)
        {
          if (j==w || j==1)
            putchar('*');
          else
            putchar(' ');
        }
      } putchar('\n');
    }
  }
  return 0;
}