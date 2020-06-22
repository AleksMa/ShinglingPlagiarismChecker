#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{

  if (argc != 4) {  
    printf("Usage: frame <height> <width> <text>\n");
    return 0;
  }

  if ((atoi(argv[1]) < 3) || ((atoi(argv[2])- 2) < strlen(argv[3]))) printf("Error\n");
  else
  {

  int i = 0, j = 0;//i - строки, j - столбцы
  long h = atoi(argv[1]);
  long w = atoi(argv[2]);
  long l = strnlen(argv[3],255);
  long midh= (h+1)/2-1;
  
  for (i = 0; i < w; i++) printf("*");
  printf("\n");
  



   for (j=1;j<h-1;j++) {

     if (j!=midh) {
       for(i=0;i<w;i++) { 
          if ((i == 0) || (i == w-1)) printf("*");
          else printf(" ");
       }
      printf("\n");    
     }

     else {
       printf("*");
       for (i=0;i<(w-2-l)/2;i++) printf(" ");
       printf("%s", argv[3]);
       for (i=(w-l)/2+l;i<w-1;i++) printf(" ");
       printf("*");
       printf("\n");
     }
 
   }

  for (i = 0; i < w; i++) printf("*");
  printf("\n");


  }
return 0;
}
