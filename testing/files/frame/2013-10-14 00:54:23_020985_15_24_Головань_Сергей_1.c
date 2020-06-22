#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
  unsigned long i, j, height, width, len;
  if (argc!=4) {
        printf("Usage: frame <height> <width> <text>\n");
  } else {
	height=atol(argv[1]);
	width=atol(argv[2]);
	len=strlen(argv[3]);
	if ((len>(width-2)) || (height<3)) {
	      printf("Error\n");
	} else {
	      for (i=0; i<height; i++) {
		  for (j=0; j<width; j++) {
		      if ((i==0) || (i==height-1)) printf("*");
		      else {
			  if (i!=(((height-1)/2))) {
			      if ((j==0) || (j==width-1)) printf("*");
			      else printf(" ");
			  } else {
			    if ((j==0) || (j==width-1)) printf("*");
				else if ((j<((width-len)/2) ) || (j>((width-len)/2+len-1))) printf(" ");
					else printf("%c", argv[3][j-(width-len)/2]);
			  }
			}
		    }
		printf("\n");
	      }
	}
  }
} 