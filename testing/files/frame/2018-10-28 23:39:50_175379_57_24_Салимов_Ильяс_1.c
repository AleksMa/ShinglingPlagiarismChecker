#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int main(int argc,char **argv){
        if (argc != 4){ 
                printf("Usage: frame <height> <width> <text>\n"); 
                return 0;
        } 
        int x=atoi(argv[1]),y=atoi(argv[2]),l=strlen(argv[3]),i,j,m=x/2; 
        if(2*m==x) 
                m-=1; 
        if((x>2)&&(y>l+1)){ 
                for(i=0;i<y;i++) 
                        printf("*"); 
                printf("\n"); 
                for(i=1;i<x-1;i++){ 
                        if (i == m) { 
                                printf("*"); 
                                for (j=1;j<(y-l)/2;j++) 
                                        printf(" "); 
                                printf("%s",argv[3]); 
                                for(j=1;j<(y-l+1)/2;j++) 
                                        printf(" "); 
                                printf("*\n");
                                } 
                        else { 
                                printf("*"); 
                                for(j=1;j<=y-2;j++) 
                                        printf(" "); 
                                printf("*\n");
                        }
                } 
                for(i=0;i<y;i++){ 
                        if(i==(y-1)) 
                                printf("*\n"); 
                        else 
                                printf("*");
                }
        } 
        else 
                printf("Error\n"); 
        return 0;
}
