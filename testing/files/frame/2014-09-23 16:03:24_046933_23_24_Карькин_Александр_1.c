#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv) {
   
   if(argc!=4)
   {
     printf("Usage: frame <height> <width> <text>\n");
     return 0;
   }
   int n=atoi(argv[1]), m=atoi(argv[2]);
   char *s=argv[3];
   
   if((n>2) && (m-2>=strlen(s)))
   {
     int i,j;
     for(i=0;i<m;++i)
       printf("*");
     printf("\n");
     
     for(i=0;i<(n-1)/2-1;++i)
     {
       printf("*");
       for(j=0;j<m-2;++j)
         printf(" ");
       printf("*\n");
     }
     
     printf("*");
     for(i=0;i<(m-2-strlen(s))/2;++i)
       printf(" ");
     printf("%s",s);
     for(i=0;i<(m-1-strlen(s))/2;++i)
       printf(" ");
     printf("*\n");
     
     for(i=0;i<n/2-1;++i)
     {
       printf("*");
       for(j=0;j<m-2;++j)
         printf(" ");
       printf("*\n");
     }
     
     for(i=0;i<m;++i)
       printf("*");
     printf("\n");
   }
   
   else
     printf("Error\n");
     
   return 0;
 }