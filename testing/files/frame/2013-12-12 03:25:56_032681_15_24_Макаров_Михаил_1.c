#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 4) printf("Usage: frame <height> <width> <text>");
  else{     
    int i,j,k,x,y,z,l;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    k = strlen(argv[3]);
    if (x % 2 == 0) l = x / 2 - 1 ;
    else l = x / 2 ;
    z = (y - k) / 2 ;
    //printf("%d %d %d\n",x / 2,y,z);
    if (x < 3 || y - 2 < strlen(argv[3])) printf("Error");
    else{
      for (i = 0; i < x; i++){
        if (i == 0 || i == x - 1 ){ for (j = 0; j < y;j++) printf("*");
	  printf("\n");
	  if ( i == x-1) break;
	  continue;
	}
	if (i == l){
	  printf("*");
	  for (j = 1; j < z;j++) printf(" ");
	  printf("%s",argv[3]);
	  for (j = z + strlen(argv[3]); j < y - 1 ; j++) printf(" ");
	  printf("*\n");
	 // continue;
	}else{
	   printf("*");
	   for (j = 1; j < y - 1;j++) printf(" ");
	   printf("*\n");
	}
      }
    }
  }
}
    