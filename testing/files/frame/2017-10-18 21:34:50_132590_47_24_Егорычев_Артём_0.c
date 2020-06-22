#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

const char c = '*';
const char c_empty = ' ';


void print_char(int , char );

void print_char(int max_size, char symbol){

   int i;

   for(i = 1; i <= max_size; i++){
       printf("%c",symbol);
   }
}

int main(int argc, char** argv)
{
   int horis_size, vert_size, str_length;

   if(argc != 4){
     printf("Usage: frame <height> <width> <text>");
     return 0;
}

   vert_size = atoi(argv[1]);
   horis_size = atoi(argv[2]);

   str_length = strlen(argv[3]);

   if((str_length > horis_size-2) || (vert_size < 3)){
      printf("Error");
      return 0;
   }

   int middle_v = (vert_size+1)/2;

   int middle_empty = (horis_size - 2 - str_length)/2;
   int rest_empty = horis_size - 2 - str_length - middle_empty;

   int iv;

   for(iv = 1; iv <= vert_size; iv++){
      if(iv == 1 || iv == vert_size){
          if(iv == vert_size) printf("\n");
          print_char(horis_size, c);
      }else if(iv == middle_v){
          printf("\n");
          print_char(1,c);
          print_char(middle_empty,c_empty);
          printf("%s",argv[3]);
          print_char(rest_empty,c_empty);
          print_char(1,c);
      }else{
          printf("\n");
          print_char(1, c);
          print_char(horis_size-2, c_empty);
          print_char(1, c);
      }
   }

   return 0;

}