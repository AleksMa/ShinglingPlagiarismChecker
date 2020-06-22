#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv)
{ 
    int otst,n=0,ser,i,k,cpr;
    char str;
    if  (argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    if ((atoi(argv[2]))-strlen(argv[3])>1 && atoi(argv[2])>2  && atoi(argv[1])>2){
        while (n<atoi(argv[2])){
               printf("*"); 
               n++;
               }
        n=0;
        printf("\n");
        if (atoi(argv[1])%2!=0)
                ser=atoi(argv[1])-(atoi(argv[1])-1)/2;
        else ser=atoi(argv[1])/2;
        for (i=1;i<ser-1;i++){
                printf("*") ;
                for (k=2;k<atoi(argv[2]);k++)
                        printf(" ") ;
                printf("*") ;
                printf("\n") ;
        }
        otst=((atoi(argv[2])-2)-strlen(argv[3]))/2;
        printf("*");
        for (i=2;i<=otst+1;i++)
                printf(" ");
        printf("%s", argv[3]);
        for (i=otst+strlen(argv[3]);i<atoi(argv[2])-2;i++)
                 printf(" ");
        printf("*") ;
        printf("\n") ;
        for (i=ser+1;i<atoi(argv[1]);i++){
                printf("*") ;
                for (k=2;k<atoi(argv[2]);k++)
                        printf(" ") ;
                printf("*") ;
                printf("\n") ;
        }
        while (n<atoi(argv[2])){
                printf("*"); 
                n++;
         }
        printf("\n");
   }
else printf("Error");
return 0;
}