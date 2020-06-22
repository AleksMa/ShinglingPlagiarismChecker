#include<stdio.h>
#include <string.h>
 
int main(int argc, char *argv[]){
  if(argc!= 4) {
  printf("Usage: frame <height> <width> <text>");
  return 0;
  }
 else if (((strlen(argv[3])) > (atoi(argv[2]) - 2)) || (atoi(argv[1]) < 3))printf ("Error");
 else{
  int width = (atoi(argv[2])), height = (atoi(argv[1]));
  int i = 0;
 
    for (i = 0; i < width; i++)
      printf("*");
      printf("\n");
   
  int i2 = 0, mid;
  mid = (height - 1) / 2;
    for (i = 1; i < mid; i++) {
    printf("*");
    for (i2 = 1; i2 < width - 1; i2++)
    printf(" ");
    printf("*");
    printf("\n");
    }
 
    int prob, s;
      s = strlen(argv[3]);
      prob = ((width - s - 2) / 2);
      printf("*");
        for (i = 1; i <= prob; i++)
        printf(" ");
      printf("%s", argv[3]);
        for (i = prob + s + 1; i < width - 1; i++)
        printf(" ");
      printf("*");
      printf("\n");
 
 for (i= mid+1; i < height - 1; i++) {
    printf("*");
    for (i2 = 1; i2 < width - 1; i2++)
    printf(" ");
    printf("*");
    printf("\n");
    }
   
    for (i = 0; i < width; i++)
      printf("*");
      printf("\n");
 }
}