#include <stdio.h>

int main (int argc, char *argv[])

{
  int i, j, w, h, k, l;
  if (argc!=4) 
  {
    printf ("usage <heigth> <width> <text>\n");
    return 1;
   }
  h=atoi(argv[1]);
  w=atoi(argv[2]);
  l=strnlen(argv[3]);
  if (h<3 || l>(w-2))
  {
    printf ("Error\n");
    return 2;
  }  
  for (i=0; i<w; i++)
    printf ("*");
  printf ("\n");
  if (h%2 != 0) 
  {
    for (i=0; i<((h/2)-1); i++)
      {
        printf ("*");
	for (j=0; j<(w-2); j++)
	  printf (" ");
	printf ("*\n");
      }
  } else
  {
    for (i=0; i<((h/2)-2); i++)
      {
	printf ("*");
	for (j=0; j<(w-2); j++)
	  printf (" ");
	printf ("*\n");
      }
  }
  printf ("*");
  for (i=0; i<(((w-2)-l)/2); i++)
    printf (" ");
  printf ("%s", argv[3]);
  if (l%2 != 0) 
  {
    for (i=0; i<(((w-2)-l)/2+1); i++)
      printf (" ");
  } else
  {
    for (i=0; i<(((w-2)-l)/2); i++)
      printf (" ");
  }
  printf ("*\n");
  if (h%2 !=0 ) 
  {
    for (i=0; i<((h/2)-1); i++)
      {
	printf ("*");
	for (j=0; j<(w-2); j++)
	  printf (" ");
	printf ("*\n");
      }
  } else 
  {
     for (i=0; i<((h/2)-1); i++)
      {
	printf ("*");
	for (j=0; j<(w-2); j++)
	  printf (" ");
	printf ("*\n");
      }
  }
  for (i=0; i<w; i++) printf ("*");
  printf ("\n");
  return 0;
}