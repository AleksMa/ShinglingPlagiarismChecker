#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int x,y;
  if (argc != 4) {
    printf("Usage: frame <height> <width> <text>\n");
    return 0;
  }
  if (atoi(argv[1])<3 || (atoi(argv[2]) - 2) < strlen(argv[3])) {
    printf("Error\n");
    return 0;
  }
  int midx = (atoi(argv[2]) - strlen(argv[3])) / 2, midy = atoi(argv[1]) / 2 ;
  if (atoi(argv[1]) % 2) midy++;
  for (x = 0; x < atoi(argv[2]); x++) printf("*");
  printf("\n");
  for (y = 2; y < atoi(argv[1]); y++) {
    for (x = 1; x < atoi(argv[2]); x++) {
      if (x == 1) printf("*");
      if (x == atoi(argv[2])-1) printf("*");
      if (x >= midx && y == midy && x < midx + strlen(argv[3])) printf("%c", argv[3][x-midx]);
      else if (x != atoi(argv[2])-1 || x !=0) printf(" ");
    }
    printf("\n");
  }
  for (x = 0; x < atoi(argv[2]); x++) printf("*");
  printf("\n");
  return 0;
}