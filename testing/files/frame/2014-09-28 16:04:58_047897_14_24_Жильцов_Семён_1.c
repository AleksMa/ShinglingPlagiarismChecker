#include <stdio.h>
 
int main(int argc,char **argv)
{  
        int i,j;
    if (argc!=4)   printf("Usage: frame <height> <width> <text>");
    
    else {
        int height=atoi(argv[1]);
        int widht=atoi(argv[2]);
        char *s=argv[3];
        int dl=strlen(s);
        if (widht-2<dl || height<3) {
            printf("Error");
            return 0;
        }
        
        
        for (i=1;i<=widht;i++) 
            printf("*");
        
        printf("\n");
       
        for (i=1;i<=height-2;i++) {
            printf("*");
            if (((height-1)/2)==i) {
                for (j=1;j<=(int)((widht-2-dl)/2);j++)
                    printf(" ");
                printf("%s",s);
               
                for (j=1;j<=(widht-2-dl)-((widht-2-dl)/2);j++)
                    printf(" ");
            }
            else
                for (j=1;j<=widht-2;j++) {
                    printf(" ");
                }
            printf("*\n");
        }
        for (i=1;i<=widht;i++) {
            printf("*");
        }
    }
    return 0;
}