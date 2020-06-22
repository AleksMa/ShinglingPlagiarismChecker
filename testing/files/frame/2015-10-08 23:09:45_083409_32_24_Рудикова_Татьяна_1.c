#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    
    int i,j, lenght = strlen(argv[3]), 
        height = atoi(argv[1]), 
        width = atoi(argv[2]);
	
     if (lenght > width - 2 || height < 3) printf("Error\n");
         else {
	      for (i = 0; i < width; i++, printf("*"));
	      printf("\n");
	      
	      for (i = 0; i < (height - 3)/2; i++){
		  printf("*");
		  for (j = 1; j < width - 1;j++, printf(" "));
		  printf("*\n");
	      }
	      printf("*");
	      
	      for (i = 0; i < (width - lenght - 2)/2;i++, printf(" "));
	         
	      printf("%s", argv[3]);
	      
	      for (i = 0; i < (width - lenght - 1)/2;i++, printf(" "));
	      
	      printf("*\n");
	      
	      for (i = 0; i < (height - 2)/2; i++){
		  printf("*");
		  for (j = 1; j < width - 1;j++,  printf(" "));

	      printf("*\n");}
	          
              for (i = 0; i < width; i++, printf("*"));
	 }
}