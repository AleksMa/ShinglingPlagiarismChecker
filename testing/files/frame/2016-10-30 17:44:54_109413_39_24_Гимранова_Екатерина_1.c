#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc!=4) {
    printf("Usage: frame <height> <width> <text> \n");
    return 0;
  }
  int height=atoi(argv[1]),width=atoi(argv[2]);
  int k=strlen(argv[3]),i,j,distance_right,distance_left,number_h;
  int a[height][width];

  if ((width<k+2) || (height<=2))
    printf("Error \n");
  else {
    for (j=0; j<= width - 1;j++) {
      a[0][j]=1;
      a[height-1][j]=1;
    }
    for (i=1;i<= height-2;i++) {
      a[i][0]=1;
      a[i][width-1]=1;
    }
    if (((width%2 + k%2)%2) == 0) distance_right = (width-k)/2 - 1;
    else distance_right = (width - k)/2;
    distance_left = width - distance_right - k - 2;
    if (height%2==1) number_h = height/2;
    else number_h = (height-1)/2;
    for (i=1;i<=number_h-1;i++)
      for (j=1;j<=width-2;j++)
        a[i][j]=0;
    for (i=number_h+1;i<height-1;i++)
      for (j=1;j< width-1;j++)
        a[i][j]=0;
    for (j=1;j<=distance_left;j++)
      a[number_h][j] = 0;
    for (j=width-2; j>= width-distance_right-1; j--)
      a[number_h][j] = 0;
    for (j=1+distance_left;j<=distance_left+k;j++)
      a[number_h][j] = 5;
    for (i=0;i<height;i++)
      for (j=0;j<width;j++) {
        if (a[i][j]==0) {
          if (j== width - 1) {
            printf(" ");
            printf("\n");
          }
          else printf(" ");
        }
        if (a[i][j]==1) {
          if (j== width - 1) {
            printf("*");
            printf("\n");
          }
          else printf("*");
        }
        if (a[i][j]==5)
            printf("%c", argv[3][j - distance_left - 1]);
      }
  }
  return 0;
}
