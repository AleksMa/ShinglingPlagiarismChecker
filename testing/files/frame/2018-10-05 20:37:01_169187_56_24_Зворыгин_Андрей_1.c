#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv) {
    int i=0;
    int a=0;
    int b=0;
    int j=0;
    int k=1;
    if(argc!=4){
       printf("Usage: frame <height> <width> <text>");
       return 0;
    }
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    if((b<strlen(argv[3])+2) || a<=2){
        printf("Error");
        return 0;
    }
    int x=(b-strlen(argv[3]))/2;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(i==0 || i==a-1){
                printf("*");
            }
            else{
                if(j==0 || j==b-1){
                    printf("*");
                }
                else{
                    if(j==x && i==(a+1)/2-1){
                        printf("%s", argv[3]);
                        j=j+strlen(argv[3])-1;
                    }
                    else{
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
